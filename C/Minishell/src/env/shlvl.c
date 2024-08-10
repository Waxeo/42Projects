/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:49:43 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/22 10:49:43 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_shlvl(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	get_shlvl(t_list *env)
{
	int		shlvl;
	char	*value;
	char	*shell_lvl;
	char	*new_shlvl;

	shell_lvl = search_var(env, "SHLVL");
	if (!shell_lvl)
		return ;
	value = get_var_value(shell_lvl);
	if (!value || check_shlvl(value))
		return ;
	shlvl = ft_atoi(value) + 1;
	free(value);
	value = ft_itoa(shlvl);
	new_shlvl = ft_strjoin("SHLVL=", value);
	modify_var(env, "SHLVL=", new_shlvl);
	free(value);
	free(new_shlvl);
}
