/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:53 by abiddane          #+#    #+#             */
/*   Updated: 2023/06/02 10:15:54 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_echo_flag(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		if (str[1] == 'n')
		{
			while (str[++i])
			{
				if (str[i] != 'n')
					return (1);
			}
			return (0);
		}
		return (1);
	}
	return (1);
}

void	echo_flag(char **cmd)
{
	int	i;

	i = 2;
	while (cmd[i] && !check_echo_flag(cmd[i]))
		i++;
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 2);
		i++;
		if (!cmd[i])
			return ;
		ft_putstr_fd(" ", 2);
	}
}

void	echo_cmd(char **cmd, t_data *data)
{
	int	i;

	if (!cmd[1])
		printf("\n");
	else if (!check_echo_flag(cmd[1]))
		echo_flag(cmd);
	else
	{
		i = 1;
		while (cmd[i])
		{
			printf("%s", cmd[i]);
			i++;
			if (!cmd[i])
			{
				printf("\n");
				data->status = 0;
				return ;
			}
			printf(" ");
		}
	}
}
