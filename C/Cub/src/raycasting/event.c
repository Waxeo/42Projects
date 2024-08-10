/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:39:14 by abiddane          #+#    #+#             */
/*   Updated: 2023/09/27 18:08:02 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_move(t_struct *all, double move_speed)
{
	if (all->data->front)
	{
		if (all->data->sprint == 1)
			move_speed *= 3;
		if (all->data->map[(int)(all->algo->pos.x + all->algo->dir.x * \
		move_speed)][(int)(all->algo->pos.y)] != '1')
			all->algo->pos.x += all->algo->dir.x * move_speed;
		if (all->data->map[(int)(all->algo->pos.x)][(int)(all->algo->pos.y + \
		all->algo->dir.y * move_speed)] != '1')
			all->algo->pos.y += all->algo->dir.y * move_speed;
	}
	if (all->data->back)
	{
		if (all->data->sprint == 1)
			move_speed *= 3;
		if (all->data->map[(int)(all->algo->pos.x - all->algo->dir.x * \
		move_speed)][(int)(all->algo->pos.y)] != '1')
			all->algo->pos.x -= all->algo->dir.x * move_speed;
		if (all->data->map[(int)(all->algo->pos.x)][(int)(all->algo->pos.y - \
		all->algo->dir.y * move_speed)] != '1')
			all->algo->pos.y -= all->algo->dir.y * move_speed;
	}
}

void	horizontal_move(t_struct *all, double move_speed)
{
	if (all->data->right)
	{
		if (all->data->sprint == 1)
			move_speed *= 3;
		if (all->data->map[(int)(all->algo->pos.x + all->algo->plane.x * \
		move_speed)][(int)(all->algo->pos.y)] != '1')
			all->algo->pos.x += all->algo->plane.x * move_speed;
		if (all->data->map[(int)(all->algo->pos.x)][(int)(all->algo->pos.y + \
		all->algo->plane.y * move_speed)] != '1')
			all->algo->pos.y += all->algo->plane.y * move_speed;
	}
	if (all->data->left)
	{
		if (all->data->sprint == 1)
			move_speed *= 3;
		if (all->data->map[(int)(all->algo->pos.x - all->algo->plane.x * \
		move_speed)][(int)(all->algo->pos.y)] != '1')
			all->algo->pos.x -= all->algo->plane.x * move_speed;
		if (all->data->map[(int)(all->algo->pos.x)][(int)(all->algo->pos.y - \
		all->algo->plane.y * move_speed)] != '1')
			all->algo->pos.y -= all->algo->plane.y * move_speed;
	}
}

int	event(t_struct *all)
{
	all->algo->move_speed = 0.04;
	all->algo->rot_speed = 0.06;
	vertical_move(all, all->algo->move_speed);
	horizontal_move(all, all->algo->move_speed);
	rotate(all, all->algo->rot_speed);
	if (all->data->mouse % 2 == 0)
		mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, \
		SCREENWIDTH / 2, SCREENHEIGHT / 2);
	return (0);
}
