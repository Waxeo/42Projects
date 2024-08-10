/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:27:45 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/30 18:06:48 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(t_list *env, t_data *data, char **cmd, int toggle)
{
	if (cmd[1])
	{
		handle_error(1, cmd[0], NULL, "too many arguments\n");
		exit_or_return(toggle);
		data->status = 1;
		return ;
	}
	while (env != NULL)
	{
		if (ft_strchr(env->var, '='))
			printf("%s\n", env->var);
		env = env->next;
	}
	data->status = 0;
}

void	env_export(t_list *env, t_data *data)
{
	while (env != NULL)
	{
		printf("declare -x %s\n", env->var);
		env = env->next;
	}
	data->status = 0;
}
