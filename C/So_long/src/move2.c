/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:29:43 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 16:47:56 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	s_movement(t_data *data)
{
	int	i;
	int	j;

	i = data->x;
	j = data->y - 1;
	if (data->map[j][i] == '1')
		return (0);
	if (!check_move(data, i, j))
		return (0);
	data->map[j + 1][i] = '0';
	return (1);
}

int	w_movement(t_data *data)
{
	int	i;
	int	j;

	i = data->x;
	j = data->y + 1;
	if (data->map[j][i] == '1')
		return (0);
	if (!check_move(data, i, j))
		return (0);
	data->map[j - 1][i] = '0';
	return (1);
}

int	d_movement(t_data *data)
{
	int	i;
	int	j;

	i = data->x - 1;
	j = data->y;
	if (data->map[j][i] == '1')
		return (0);
	if (!check_move(data, i, j))
		return (0);
	data->map[j][i + 1] = '0';
	return (1);
}

int	a_movement(t_data *data)
{
	int	i;
	int	j;

	i = data->x + 1;
	j = data->y;
	if (data->map[j][i] == '1')
		return (0);
	if (!check_move(data, i, j))
		return (0);
	data->map[j][i - 1] = '0';
	return (1);
}
