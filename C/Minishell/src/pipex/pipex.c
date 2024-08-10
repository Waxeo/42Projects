/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:50:45 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/02 10:38:57 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_data *data, t_list *env, int i)
{
	char	**cmd;

	data->index = i;
	free(data->pid);
	cmd = start_cmd_tab(data, env, data->av[i], 2);
	if (!cmd)
	{
		if (data->here)
			free(data->here);
		free_data_env(env, data, NULL, 1);
		exit(0);
	}
	if (builtins_finder(cmd))
		exec_builtins(cmd, data, env, 1);
	if (cmd[0])
		data->cmd = cmd_final_state(data, cmd[0]);
	if (data->cmd && !isntempty(cmd))
		safe_exe(data, cmd, data->env);
	child_aux(env, data, cmd);
	exit(127);
}

void	waitin(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbcmd)
	{
		waitpid(data->pid[i], &data->status, 0);
		if (WIFEXITED(data->status))
			data->status = WEXITSTATUS(data->status);
	}
}

void	parent_process(t_data *data)
{
	safe_close(data->pipefd[1]);
	if (data->prev_pipe != -1)
		safe_close(data->prev_pipe);
	data->prev_pipe = data->pipefd[0];
}

static	int	verify_min_one(t_data *data, t_list *env, char *read)
{
	data->here_nb = count_hd(read);
	if (here_alloc(data))
		return (-1);
	if (pipex_hd_aux(env, data))
		return (-1);
	if (pipex_heart(env, data) == -1)
	{
		free_data_env(env, data, NULL, 4);
		return (-1);
	}
	return (0);
}

int	pipex(char *read, t_list *env)
{
	t_data	*data;
	int		i;

	data = starton();
	if (struct_init(data, env, read))
		return (-1);
	if (pipex_aux(data, read))
		return (-1);
	else if (data->nbcmd == 1 && is_a_built(env, data))
		return (exec_solo_built(env, data));
	if (verify_min_one(data, env, read) == -1)
		return (-1);
	safe_close(data->pipefd[0]);
	waitin(data);
	i = -1;
	while (++i < data->here_nb)
		safe_close(data->here[i].pipe[0]);
	free_data_env(env, data, NULL, 4);
	data->here_cmp = 0;
	return (data->status);
}
