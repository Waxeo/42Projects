/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:39:48 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/01 11:54:33 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_hd(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '<' && str[i + 1] == '<' && !is_in_quote(str, i))
		{
			nb++;
			i++;
		}
	}
	return (nb);
}

void	openfileshd(int index, t_here *here)
{
	char	*s;

	while (1)
	{
		s = readline(">");
		if (s == NULL)
		{
			ft_putstr_fd("bash: warning: here-document at line 1 ", 2);
			ft_putstr_fd("delimited by end-of-file (wanted ", 2);
			ft_putstr_fd(here[index].delim, 2);
			ft_putstr_fd(")\n", 2);
			break ;
		}
		if (!ft_strcmp(s, here[index].delim))
		{
			free(s);
			break ;
		}
		ft_putendl_fd(s, here[index].pipe[1]);
		free(s);
	}
	close(here[index].pipe[1]);
	close(here[index].pipe[0]);
}

static int	ft_getdelims(t_list *env, t_data *data)
{
	int		i;
	int		k;
	char	**cmd;

	i = -1;
	k = 0;
	while (data->av[++i])
	{
		cmd = ft_split(data->av[i], ' ');
		cmd = final_state(env, cmd, data);
		if (check_redir(cmd))
		{
			free_tab(data->av);
			free(data->env);
			free_tab(cmd);
			free(data->pid);
			return (1);
		}
		k = gdelims_aux(data, cmd, k);
	}
	return (0);
}

int	here_doc(t_list *env, t_data *data)
{
	int		i;
	pid_t	pid;

	if (ft_getdelims(env, data))
		return (1);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	i = -1;
	if (pid == 0)
		child_hd(env, data);
	else if (pid > 0)
	{
		while (++i < data->here_nb)
		{
			free(data->here[i].delim);
			safe_close(data->here[i].pipe[1]);
		}
	}
	waitpid(pid, &data->status, 0);
	if (data->status == 33280)
		data->status = 130;
	return (0);
}
