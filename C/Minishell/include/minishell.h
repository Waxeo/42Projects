/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:17:28 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/02 10:20:44 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	char			*var;
	struct s_list	*next;
}				t_list;

typedef struct s_here
{
	char	*delim;
	int		pipe[2];
}			t_here;

typedef struct s_data
{
	int		pipefd[2];
	int		builtin;
	int		builtout;
	int		fdin;
	int		fdout;
	int		nbcmd;
	int		here_cmp;
	int		here_nb;
	int		prev_pipe;
	int		*pid;
	int		status;
	int		here_doc;
	int		ac;
	int		index;
	char	**av;
	char	*cmd;
	char	**env;
	char	**path;
	t_here	*here;
}			t_data;

/* builtins */
	/* builtins_utils.c */
void	error_home(char *home, char *cdir, int toggle);
int		builtins_finder(char **cmd);
void	exec_builtins(char **cmd, t_data *data, t_list *env, int toggle);
int		exit_or_return(int toggle);
t_list	*return_perror(t_list *env, t_data *data, char *buf, int toggle);
	/* cd.c */
t_list	*cd_cmd(t_list *env, char **cmd, t_data *data, int toggle);
	/* echo.c */
void	echo_cmd(char **cmd, t_data *data);
	/* env.c */
void	env_cmd(t_list *env, t_data *data, char **cmd, int toggle);
void	env_export(t_list *env, t_data *data);
	/* error.c */
void	handle_perror(char *command, t_data *data, char *cdir, int toggle);
void	handle_error(int n, char *cmd1, char *cmd2, char *error);
	/* exit.c */
void	exit_cmd(t_list *env, t_data *data, char **cmd, int toggle);
	/* export.c */
t_list	*export_cmd(t_list *env, t_data *data, char **cmd, int toggle);
	/* pwd.c */
void	pwd_cmd(t_data *data, int toggle);
	/* unset.c */
void	unset_cmd(t_list *env, char **cmd, t_data *data);

/* -------------------------------------------------------------------------- */

/* env */
	/* env_utils.c */
char	*get_var_name(char *str);
char	*get_var_value(char *str);
int		ft_lstsize(t_list *lst);
	/* init.c */
t_list	*env_init(char **envp);
char	**env_tab_init(t_list *env);
char	*search_var(t_list *env, char *name);
void	modify_var(t_list *env, char *name, char *var);
	/* shlvl.c */
void	get_shlvl(t_list *env);

/* -------------------------------------------------------------------------- */

/* parsing */
	/* command_utils.c */
int		check_redir(char **tab);
char	**delete_redir(char **tab);	
	/* command.c */
char	**split_pipe(char *str);
char	**final_state(t_list *env, char **tab, t_data *data);
char	**start_cmd_tab(t_data *data, t_list *env, char *str, int toggle);
	/* expand_utils.c */
void	free_str(char *cmd, char *value, char *name, char *after);
int		push_i(t_list *env, char *name, int i);
void	tab_value_err(t_data *data, char **tab, char *str, int i);
void	tab_value(t_list *env, char **tab, char *str, int i);
int		push_to_expand(char *str, int i);
	/* expand.c */
char	*get_expand_name(char *str);
char	*get_before_expand(char *str, int j);
char	*get_after_expand(char *str);	
char	*init_value(t_list *env, char *str, char *name, int *i);	
char	*expand(t_list *env, char *cmd, t_data *data);
	/* quote.c */
char	*parse_quote(char *str);
int		count_quote(char *cmd, t_data *data);
int		is_in_quote(char *str, int n);
char	*delete_quote(char *str, t_data *data);
	/* space_line.c */
char	*new_line(char *read);

/* -------------------------------------------------------------------------- */

/*Pipex*/
	/* exec.c */
int		exec_solo_built(t_list *env, t_data *data);	
int		exec(t_list *env, t_data *data, int i);
int		is_a_built(t_list *env, t_data *data);
int		pipex_heart(t_list *env, t_data *data);
	/*files.c*/
void	open_in(t_data *data, t_list *env, char **cmd, int i);
void	open_out(t_data *data, t_list *env, char **cmd, int i);
void	close_all_sides(t_data *data);
	/* free.c */
void	free_data_env(t_list *env, t_data *data, char **cmd, int toggle);
void	child_aux(t_list *env, t_data *data, char **cmd);
int		pipex_aux(t_data *data, char *read);
int		pipex_hd_aux(t_list *env, t_data *data);
	/*pipex_utils.c*/
int		struct_init(t_data *data, t_list *env, char *read);
void	free_tab(char **tab);
char	**get_cmd_path(t_data *data);
char	*cmd_final_state(t_data *data, char *cmd);
	/* pipex_utils2.c*/
int		heredoc_count(char **tab);
void	dup_n_close(int oldfd, int newfd);
int		isaredirection(char *str);
void	redir_finder(t_data *data, t_list *env, char **cmd, int toggle);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
	/*pipex.c*/
void	child_process(t_data *data, t_list *env, int i);	
void	parent_process(t_data *data);
int		pipex(char *read, t_list *env);
	/*security.c*/
int		safe_piping(int *pipefd);
void	safe_exe(t_data *data, char **cmd, char **env);
void	safe_close(int fd);
void	safe_dup(int oldfd, int newfd);
	/*where_doc.c*/
int		count_hd(char *str);
void	openfileshd(int index, t_here *here);	
int		here_doc(t_list *env, t_data *data);
	/* where_doc_utils.c */
int		here_alloc(t_data *data);
void	free_here(t_data *data);
int		gdelims_aux(t_data *data, char **cmd, int k);

/* -------------------------------------------------------------------------- */

/* signal */
	/* signal. c*/
void	handler_sig(int sig);
void	handler_hd(int sig);
void	child_hd(t_list *env, t_data *data);
void	handler_cmd(int sig);
void	handler_prout(int sig);

/* -------------------------------------------------------------------------- */

/* utils */
	/* ft_split.c */
char	**ft_split(const char *s, char c);
	/* ft_strjoin.c */
void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_calloc(size_t nbr, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
	/*get_next_line.c*/
char	*get_next_line(int fd);
	/* itoa.c */
char	*ft_itoa(int n);	
	/* lst_utils.c */
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_lst(t_list *list);
	/* utils.c */
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		tablen(char **tab);
	/* utils2.c */
char	*ft_strchr(const char *s, int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_str_isdigit(char	*str);
char	*ft_strjoin_free(char *s1, char *s2);
	/* utils3.c */
int		ft_atoi(const char *nptr);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strstr(char *str, char *to_find);
int		isntempty(char **cmd);
int		ft_isdigit(int c);

t_data	*starton( void );

#endif