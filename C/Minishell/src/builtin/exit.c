/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:50:02 by abiddane          #+#    #+#             */
/*   Updated: 2023/06/02 10:27:09 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit(t_data *data, t_list *env, char **cmd, int n)
{
	free_lst(env);
	free_tab(cmd);
	free_tab(data->av);
	free(data->env);
	if (data->nbcmd == 1)
	{
		free(data->pid);
		dup_n_close(data->builtin, STDIN_FILENO);
		dup_n_close(data->builtout, STDOUT_FILENO);
	}
	else if (data->nbcmd > 1)
		free(data->here);
	exit(n);
}

void	exit_cmd(t_list *env, t_data *data, char **cmd, int toggle)
{
	if (data->nbcmd == 1)
		printf("exit\n");
	if (!cmd[1])
		ft_exit(data, env, cmd, data->status);
	else if (cmd[1] && !ft_str_isdigit(cmd[1]) && !cmd[2])
		ft_exit(data, env, cmd, ft_atoi(cmd[1]));
	else if (cmd[1] && ft_str_isdigit(cmd[1]))
	{
		handle_error(1, cmd[0], cmd[1], "numeric argument required\n");
		ft_exit(data, env, cmd, 2);
	}
	else
	{
		handle_error(1, cmd[0], NULL, "too many arguments\n");
		exit_or_return(toggle);
		data->status = 1;
		return ;
	}
}
