/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:55:33 by abiddane          #+#    #+#             */
/*   Updated: 2023/06/02 10:30:22 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_solo_built(t_list *env, t_data *data)
{
	char	**tab;

	data->builtin = dup(STDIN_FILENO);
	data->builtout = dup(STDOUT_FILENO);
	tab = start_cmd_tab(data, env, data->av[0], 1);
	exec_builtins(tab, data, env, 0);
	free_tab(tab);
	free(data->pid);
	free(data->env);
	free_tab(data->av);
	dup_n_close(data->builtin, STDIN_FILENO);
	dup_n_close(data->builtout, STDOUT_FILENO);
	return (0);
}

int	exec(t_list *env, t_data *data, int i)
{
	if (safe_piping(data->pipefd) == -1)
		return (-1);
	signal(SIGINT, &handler_cmd);
	data->pid[i] = fork();
	if (data->pid[i] == 0)
		child_process(data, env, i);
	else if (data->pid[i] > 0)
		parent_process(data);
	return (0);
}

int	is_a_built(t_list *env, t_data *data)
{
	char	**tab;
	int		ret;

	tab = start_cmd_tab(data, env, data->av[0], 0);
	ret = builtins_finder(tab);
	if (tab)
		free_tab(tab);
	return (ret);
}

static	int	is_a_built_na(t_list *env, t_data *data, int i)
{
	char	**tab;
	int		ret;

	tab = start_cmd_tab(data, env, data->av[i], 0);
	ret = builtins_finder(tab);
	if (tab)
		free_tab(tab);
	return (ret);
}

int	pipex_heart(t_list *env, t_data *data)
{
	int	i;

	i = 0;
	while (i + data->here_doc < data->nbcmd + data->here_doc)
	{
		if (exec(env, data, i) == -1)
			return (-1);
		if (is_a_built_na(env, data, i))
			waitpid(data->pid[i], &data->status, 0);
		if (data->here_nb && ft_strstr(data->av[i], "<<"))
			data->here_cmp++;
		i++;
	}
	return (0);
}
