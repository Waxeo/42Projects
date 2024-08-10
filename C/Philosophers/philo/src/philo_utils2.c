/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:10:51 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/17 14:48:51 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_parse(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf(BLUE"./philo\nnumber_of_philosophers\ntime_to_die\ntime_to_eat\n\
time_to_sleep\n[number_of_times_each_philosopher_must_eat]\n"DEF_COLOR);
		return (1);
	}
	while (i < argc)
	{
		if (!ft_checklen(argv[i])|| !ft_isdigit(argv[i])
			|| atoi_ft(argv[i]) < 0 || atoi_ft(argv[i]) > 2147483647)
		{
			printf(RED"Invalid args\n"DEF_COLOR);
			return (1);
		}
		i++;
	}
	return (0);
}
