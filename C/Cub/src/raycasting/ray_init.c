/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:15:19 by abiddane          #+#    #+#             */
/*   Updated: 2023/09/27 17:27:10 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_init(t_data *data, t_algo *algo)
{
	ray_init2(data, algo);
	if (data->map[(int)algo->pos.x][(int)algo->pos.y] == 'N')
	{
		algo->dir.x = -1;
		algo->plane.y = 0.66;
	}
	else if (data->map[(int)algo->pos.x][(int)algo->pos.y] \
		== 'S')
	{
		algo->dir.x = 1;
		algo->plane.y = -0.66;
	}
	else if (data->map[(int)algo->pos.x][(int)algo->pos.y] \
		== 'E')
	{
		algo->dir.y = 1;
		algo->plane.x = 0.66;
	}
	else if (data->map[(int)algo->pos.x][(int)algo->pos.y] \
		== 'W')
	{
		algo->dir.y = -1;
		algo->plane.x = -0.66;
	}
}

void	ray_init2(t_data *data, t_algo *algo)
{
	algo->pos.x = find_playerx(data->map) + 0.5;
	algo->pos.y = find_playery(data->map) + 0.5;
	algo->plane.y = 0;
	algo->plane.x = 0;
	algo->dir.x = 0;
	algo->dir.y = 0;
}

void	ray_dir_cam_init(t_algo *algo)
{
	algo->camera_x = 2 * algo->x / (double)SCREENHEIGHT - 1.83;
	algo->ray_dir.x = algo->dir.x + algo->plane.x * \
	algo->camera_x;
	algo->ray_dir.y = algo->dir.y + algo->plane.y * \
	algo->camera_x;
	algo->map.x = (int)algo->pos.x;
	algo->map.y = (int)algo->pos.y;
	if (algo->ray_dir.x == 0)
		algo->delta_dist.x = 1e30;
	else
		algo->delta_dist.x = ft_fabs(1 / algo->ray_dir.x);
	if (algo->ray_dir.y == 0)
		algo->delta_dist.y = 1e30;
	else
		algo->delta_dist.y = ft_fabs(1 / algo->ray_dir.y);
}

void	ray_side_init(t_algo *algo)
{
	if (algo->ray_dir.x < 0)
	{
		algo->step.x = -1;
		algo->side_dist.x = (algo->pos.x - algo->map.x) * \
		algo->delta_dist.x;
	}
	else
	{
		algo->step.x = 1;
		algo->side_dist.x = (algo->map.x + 1 - algo->pos.x) * \
		algo->delta_dist.x;
	}
	if (algo->ray_dir.y < 0)
	{
		algo->step.y = -1;
		algo->side_dist.y = (algo->pos.y - algo->map.y) * \
		algo->delta_dist.y;
	}
	else
	{
		algo->step.y = 1;
		algo->side_dist.y = (algo->map.y + 1 - algo->pos.y) * \
		algo->delta_dist.y;
	}
}
