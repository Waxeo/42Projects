/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:53:11 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/01 15:04:56 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_count(char **tab)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (tab[++i])
	{
		if (tab[i][0] == '<' && tab[i][1] == '<')
			count++;
	}
	return (count);
}

void	dup_n_close(int oldfd, int newfd)
{
	safe_dup(oldfd, newfd);
	safe_close(oldfd);
}

int	isaredirection(char *str)
{
	if (!ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, ">>"))
		return (2);
	if (!ft_strcmp(str, "<"))
		return (3);
	if (!ft_strcmp(str, "<<"))
		return (4);
	return (0);
}

static	void	open_redir(t_data *data, t_list *env, char **cmd, int i)
{
	int	type;

	type = isaredirection(cmd[i]);
	if (type == 1 || type == 2)
		open_out(data, env, cmd, i);
	if (type == 3)
		open_in(data, env, cmd, i);
	if (data->here_nb && type == 4)
		safe_dup(data->here[data->here_cmp].pipe[0], STDIN_FILENO);
	if (type == 1 || type == 2)
		dup_n_close(data->fdout, STDOUT_FILENO);
	if (type == 3)
		dup_n_close(data->fdin, STDIN_FILENO);
}

void	redir_finder(t_data *data, t_list *env, char **cmd, int toggle)
{
	int	i;

	i = 0;
	if (data->index != 0)
		dup_n_close(data->prev_pipe, STDIN_FILENO);
	if (data->index != data->nbcmd - 1)
		safe_dup(data->pipefd[1], STDOUT_FILENO);
	if (toggle > 1)
		close_all_sides(data);
	while (cmd[i])
	{
		open_redir(data, env, cmd, i);
		i++;
	}
	i = -1;
	while (++i < data->here_nb)
		safe_close(data->here[i].pipe[0]);
}
