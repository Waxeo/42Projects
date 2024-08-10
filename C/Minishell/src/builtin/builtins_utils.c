/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:24:27 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/01 13:03:39 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_home(char *home, char *cdir, int toggle)
{
	ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	free(home);
	free(cdir);
	if (toggle)
		exit(1);
	else
		return ;
}

int	builtins_finder(char **cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd[0], "echo"))
		return (1);
	else if (!ft_strcmp(cmd[0], "cd"))
		return (1);
	else if (!ft_strcmp(cmd[0], "pwd"))
		return (1);
	else if (!ft_strcmp(cmd[0], "export"))
		return (1);
	else if (!ft_strcmp(cmd[0], "unset"))
		return (1);
	else if (!ft_strcmp(cmd[0], "env"))
		return (1);
	else if (!ft_strcmp(cmd[0], "exit"))
		return (1);
	return (0);
}

void	exec_builtins(char **cmd, t_data *data, t_list *env, int toggle)
{
	if (!ft_strcmp(cmd[0], "echo"))
		echo_cmd(cmd, data);
	else if (!ft_strcmp(cmd[0], "cd"))
		env = cd_cmd(env, cmd, data, toggle);
	else if (!ft_strcmp(cmd[0], "pwd"))
		pwd_cmd(data, toggle);
	else if (!ft_strcmp(cmd[0], "export"))
		env = export_cmd(env, data, cmd, toggle);
	else if (!ft_strcmp(cmd[0], "unset"))
		unset_cmd(env, cmd, data);
	else if (!ft_strcmp(cmd[0], "env"))
		env_cmd(env, data, cmd, toggle);
	else if (!ft_strcmp(cmd[0], "exit"))
		exit_cmd(env, data, cmd, toggle);
	if (toggle)
	{
		free(data->here);
		free_tab(cmd);
		free_tab(data->av);
		free_lst(env);
		free(data->env);
		exit (0);
	}
	else
		return ;
}

t_list	*return_perror(t_list *env, t_data *data, char *buf, int toggle)
{
	handle_perror("cd", data, buf, toggle);
	return (env);
}
