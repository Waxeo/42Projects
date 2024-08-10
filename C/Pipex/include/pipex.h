/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:41:09 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/05/18 15:32:15 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_data
{
	int		pipefd[2];
	int		fdin;
	int		fdout;
	int		nbcmd;
	int		prev_pipe;
	int		*pid;
	int		status;
	int		here_doc;
	char	*outfile;
	char	*infile;
	char	**cmd_options;
	char	*cmd;
	char	**env;
	char	**path;
}			t_data;

/*Pipex*/	
	/*files.c*/
void	open_in(t_data *data, char *infile);
void	open_out(t_data *data, char *outfile);
void	lim_open(t_data *data);
void	close_all_sides(t_data *data);
void	file_error(t_data *data, char *msg);	
	/*security.c*/
void	safe_piping(int *pipefd);
void	safe_exe(t_data *data, char **env);
void	safe_close(int fd);
void	safe_dup(int oldfd, int newfd);
	/*utils.c*/
void	struct_init(t_data *data, int ac, char **av, char **env);
void	free_tab(char **tab);
int		check_cmd(char *av);
char	**get_cmd_path(t_data *data);
char	*cmd_final_state(t_data *data, char *cmd);
	/*where_doc.c*/
void	limiter_child(t_data *data, char *limiter);
/*Libft*/
	/*ft_split.c*/
char	**ft_split(const char *s, char c);
	/*ft_strjoin.c*/
void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_calloc(size_t nbr, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
	/*libfiles.c*/
int		ft_strchr(char *cmd, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
	/*libfiles2.c*/
char	*get_next_line(int fd);
#endif
