/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:43:51 by abiddane          #+#    #+#             */
/*   Updated: 2023/09/27 18:11:57 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);

int	mouse_rot(int x, int y, t_data *data)
{
	int	previous_x;

	(void)y;
	data->mouse_x = SCREENWIDTH / 2;
	previous_x = data->mouse_x;
	data->mouse_x = x;
	if (data->mouse_x > previous_x)
		data->mouse_r_right = 1;
	else if (data->mouse_x < previous_x)
		data->mouse_r_left = 1;
	else
	{
		data->mouse_r_left = 0;
		data->mouse_r_right = 0;
	}
	return (0);
}
