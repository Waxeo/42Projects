/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:27:21 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/30 18:07:05 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_cmd(t_list *env, char **cmd, t_data *data)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = env;
	i = 0;
	while (cmd[++i])
	{
		while (env->next)
		{
			if (!ft_strncmp(env->next->var, cmd[i], ft_strlen(cmd[i])))
			{
				tmp2 = env->next->next;
				free(env->next->var);
				free(env->next);
				env->next = tmp2;
				break ;
			}
			env = env->next;
		}
		env = tmp;
	}
	data->status = 0;
}
