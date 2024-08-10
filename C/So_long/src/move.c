/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:29:43 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/23 13:47:43 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_data *data, int i, int j)
{
	if (data->map[j][i] == 'E')
	{
		if (data->collect != 0)
			return (0);
		ft_printf("Well Played !\nYou made %d steps.\n", data->move);
		clean_win_kill(data);
	}
	if (data->map[j][i] == '0')
	{
		data->map[j][i] = 'P';
		data->x = i;
		data->y = j;
	}
	if (data->map[j][i] == 'C')
	{
		data->map[j][i] = 'P';
		data->x = i;
		data->y = j;
		data->collect--;
	}
	return (1);
}

int	controls_working(int command, t_data *data)
{
	int	works;

	works = 0;
	if (command == 65307)
		clean_win_kill(data);
	if (command == 119 || command == 65362)
		works = s_movement(data);
	if (command == 115 || command == 65364)
		works = w_movement(data);
	if (command == 97 || command == 65361)
		works = d_movement(data);
	if (command == 100 || command == 65363)
		works = a_movement(data);
	if (works)
	{
		data->move++;
		ft_printf("%d\n", data->move);
		ft_add_image(data->map, data);
	}
	return (1);
}
