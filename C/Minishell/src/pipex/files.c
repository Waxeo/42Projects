/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:49 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/02 10:34:27 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	file_error(t_data *data, t_list *env, char **cmd, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	free_data_env(env, data, cmd, 2);
	exit(1);
}

void	open_in(t_data *data, t_list *env, char **cmd, int i)
{
	data->fdin = open(cmd[i + 1], O_RDONLY);
	if (data->fdin < 0)
		file_error(data, env, cmd, cmd[i + 1]);
}

void	open_out(t_data *data, t_list *env, char **cmd, int i)
{
	int	type;

	type = isaredirection(cmd[i]);
	if (type == 1)
		data->fdout = open(cmd[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (type == 2)
		data->fdout = open(cmd[i + 1], O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (data->fdout < 0)
		file_error(data, env, cmd, cmd[i + 1]);
}

void	close_all_sides(t_data *data)
{
	safe_close(data->pipefd[0]);
	safe_close(data->pipefd[1]);
}
