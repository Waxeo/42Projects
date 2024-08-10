/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:05:39 by abiddane          #+#    #+#             */
/*   Updated: 2023/09/27 18:12:32 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_hit(t_data *data, t_algo *algo)
{
	algo->hit = 0;
	while (algo->hit == 0)
	{
		if (algo->side_dist.x < algo->side_dist.y)
		{
			algo->side_dist.x += algo->delta_dist.x;
			algo->map.x += algo->step.x;
			algo->side = 0;
		}
		else
		{
			algo->side_dist.y += algo->delta_dist.y;
			algo->map.y += algo->step.y;
			algo->side = 1;
		}
		if (data->map[algo->map.x][algo->map.y] == '1')
			algo->hit = 1;
	}
}

void	draw_wall(t_algo *algo)
{
	if (algo->side == 0)
		algo->perp_wall_dist = algo->side_dist.x - \
		algo->delta_dist.x;
	else
		algo->perp_wall_dist = algo->side_dist.y - \
		algo->delta_dist.y;
	algo->line_height = (int)(SCREENHEIGHT / \
	algo->perp_wall_dist);
	algo->draw_start = -algo->line_height / 2 + SCREENHEIGHT / 2;
	if (algo->draw_start < 0)
		algo->draw_start = 0;
	algo->draw_end = algo->line_height / 2 + SCREENHEIGHT / 2;
	if (algo->draw_end >= SCREENHEIGHT)
		algo->draw_end = SCREENHEIGHT - 1;
}

void	get_tex(t_algo *algo)
{
	if (algo->side == 0)
		algo->wall_x = algo->pos.y + algo->perp_wall_dist * algo->ray_dir.y;
	else
		algo->wall_x = algo->pos.x + algo->perp_wall_dist * algo->ray_dir.x;
	algo->wall_x -= floor((algo->wall_x));
	algo->tex.x = (int)(algo->wall_x * 64);
	if (algo->side == 0 && algo->ray_dir.x > 0)
		algo->tex.x = 64 - algo->tex.x - 1;
	if (algo->side == 1 && algo->ray_dir.y < 0)
		algo->tex.x = 64 - algo->tex.x - 1;
	algo->walk = 1.0 * 64 / algo->line_height;
	algo->tex_pos = \
	(algo->draw_start - SCREENHEIGHT / 2 + algo->line_height / 2) * algo->walk;
	algo->y = 0;
}

void	draw_on_screen(t_struct *all, t_algo *algo, t_img *img, t_mlx *mlx)
{
	get_tex(algo);
	while (algo->y < algo->draw_start)
	{
		my_pixel_put(algo, img, all->data->crgb);
		algo->y++;
	}
	while (algo->y >= algo->draw_start && algo->y <= algo->draw_end)
	{
		algo->tex.y = (int)algo->tex_pos;
		algo->tex_pos += algo->walk;
		if (algo->side == 0 && algo->ray_dir.x < 0)
			my_pixel_put(algo, img, get_color(all, algo, img, mlx->n));
		else if (algo->side == 0 && algo->ray_dir.x >= 0)
			my_pixel_put(algo, img, get_color(all, algo, img, mlx->s));
		else if (algo->side == 1 && algo->ray_dir.y < 0)
			my_pixel_put(algo, img, get_color(all, algo, img, mlx->w));
		else if (algo->side == 1 && algo->ray_dir.y >= 0)
			my_pixel_put(algo, img, get_color(all, algo, img, mlx->e));
		algo->y++;
	}
	while (algo->y < SCREENHEIGHT)
	{
		my_pixel_put(algo, img, all->data->frgb);
		algo->y++;
	}
}

int	raycasting(t_struct *all)
{
	all->algo->x = 0;
	while (all->algo->x < SCREENWIDTH)
	{
		ray_dir_cam_init(all->algo);
		ray_side_init(all->algo);
		wall_hit(all->data, all->algo);
		draw_wall(all->algo);
		draw_on_screen(all, all->algo, all->img, all->mlx);
		
		double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

		//4 different wall directions possible
		if(all->algo->side == 0 && all->algo->ray_dir.x > 0)
		{
			floorXWall = all->algo->map.x;
			floorYWall = all->algo->map.y + all->algo->wall_x;
		}
		else if(all->algo->side == 0 && all->algo->ray_dir.x < 0)
		{
			floorXWall =all->algo->map.x + 1.0;
			floorYWall = all->algo->map.y + all->algo->wall_x;
		}
		else if(all->algo->side == 1 && all->algo->ray_dir.y > 0)
		{
			floorXWall = all->algo->map.x + all->algo->wall_x;
			floorYWall = all->algo->map.y;
		}
		else
		{
			floorXWall = all->algo->map.x + all->algo->wall_x;
			floorYWall = all->algo->map.y + 1.0;
		}

		double distWall, distPlayer, currentDist;

		distWall = all->algo->perp_wall_dist;
		distPlayer = 0.0;

		if (all->algo->draw_end < 0)
			all->algo->draw_end = SCREENHEIGHT; //becomes < 0 when the integer overflows

		//draw the floor from drawEnd to the bottom of the screen
		int	y;
		
		y = all->algo->draw_end + 1;
		while (y < SCREENHEIGHT)
		{
			currentDist = SCREENHEIGHT / (2.0 * y - SCREENHEIGHT); //you could make a small lookup table for this instead

			double weight = (currentDist - distPlayer) / (distWall - distPlayer);

			double currentFloorX = weight * floorXWall + (1.0 - weight) * all->algo->pos.x;
			double currentFloorY = weight * floorYWall + (1.0 - weight) * all->algo->pos.y;

			int floorTexX, floorTexY;
			floorTexX = (int)(currentFloorX * 64) % 64;
			floorTexY = (int)(currentFloorY * 64) % 64;

			//floor
			my_pixel_put2(all->algo->x, y, all->img, get_color2(floorTexX, floorTexY, all, all->mlx->f));
			//ceilling
			my_pixel_put2(all->algo->x, SCREENHEIGHT - y, all->img, get_color2(floorTexX, floorTexY, all, all->mlx->c));
			y++;
		}
		all->algo->x += 1;
	}
	ft_mini_map(all);
	mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win_ptr, \
	all->img->image, 0, 0);
	event(all);
	all->data->mouse_x = 0;
	return (0);
}
