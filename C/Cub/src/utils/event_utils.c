/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:39:49 by abiddane          #+#    #+#             */
/*   Updated: 2023/09/27 18:06:08 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int command, t_struct *all)
{
	if (command == 65289)
		all->data->mouse++;
	if (command == 119 || command == 65362)
		all->data->front = 1;
	if (command == 65505)
		all->data->sprint = 1;
	if (command == 115 || command == 65364)
		all->data->back = 1;
	if (command == 100)
		all->data->right = 1;
	if (command == 97)
		all->data->left = 1;
	if (command == 65363)
		all->data->r_right = 1;
	if (command == 65361)
		all->data->r_left = 1;
	if (command == 65307)
		clean_win_kill(all);
	return (0);
}

int	key_release(int command, t_struct *all)
{
	if (command == 119 || command == 65362)
		all->data->front = 0;
	if (command == 65505)
		all->data->sprint = 0;
	if (command == 115 || command == 65364)
		all->data->back = 0;
	if (command == 100)
		all->data->right = 0;
	if (command == 97)
		all->data->left = 0;
	if (command == 65363)
		all->data->r_right = 0;
	if (command == 65361)
		all->data->r_left = 0;
	return (0);
}

void	rotate_right(t_struct *all, double rot_speed)
{
	if (all->data->r_right == 1 || all->data->mouse_r_right == 1)
	{
		if (all->data->r_right == 0 || all->data->mouse_r_right == 1)
			rot_speed *= 1.5;
		all->algo->old_dir_x = all->algo->dir.x;
		all->algo->dir.x = all->algo->dir.x * cos(-rot_speed) \
		- all->algo->dir.y * sin(-rot_speed);
		all->algo->dir.y = all->algo->old_dir_x * sin(-rot_speed) \
		+ all->algo->dir.y * cos(-rot_speed);
		all->algo->old_plane_x = all->algo->plane.x;
		all->algo->plane.x = all->algo->plane.x * cos(-rot_speed) \
		- all->algo->plane.y * sin(-rot_speed);
		all->algo->plane.y = all->algo->old_plane_x * \
		sin(-rot_speed) + all->algo->plane.y * cos(-rot_speed);
	}
}

void	rotate_left(t_struct *all, double rot_speed)
{
	if (all->data->r_left == 1 || all->data->mouse_r_left == 1)
	{
		if (all->data->r_left == 0 || all->data->mouse_r_left == 1)
			rot_speed *= 1.5;
		all->algo->old_dir_x = all->algo->dir.x;
		all->algo->dir.x = all->algo->dir.x * cos(rot_speed) - \
			all->algo->dir.y * sin(rot_speed);
		all->algo->dir.y = all->algo->old_dir_x * sin(rot_speed) + \
			all->algo->dir.y * cos(rot_speed);
		all->algo->old_plane_x = all->algo->plane.x;
		all->algo->plane.x = all->algo->plane.x * cos(rot_speed) - \
			all->algo->plane.y * sin(rot_speed);
		all->algo->plane.y = all->algo->old_plane_x * \
			sin(rot_speed) + all->algo->plane.y * cos(rot_speed);
	}
}

void	rotate(t_struct *all, double rot_speed)
{
	rotate_right(all, rot_speed);
	rotate_left(all, rot_speed);
}
