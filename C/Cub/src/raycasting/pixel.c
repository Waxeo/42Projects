/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:33:59 by abiddane          #+#    #+#             */
/*   Updated: 2023/09/23 14:04:23 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_color(t_struct *all, t_algo *algo, t_img *img, void *image)
{
	char	*dst;

	if (algo->tex.x < 0 || algo->tex.y < 0 || algo->tex.y > SCREENHEIGHT - 1 \
	|| algo->tex.x > SCREENWIDTH - 1)
		return (0);
	img->data = \
	mlx_get_data_addr(image, &img->bpp, &img->size_line, &img->endian);
	if (!img->data)
		clean_win_kill(all);
	dst = img->data + (algo->tex.y * img->size_line + algo->tex.x * \
	(img->bpp / 8));
	return (*(int *)dst);
}

int	get_color2(int tx, int ty, t_struct *all, void *image)
{
	char	*dst;

	if (tx < 0 || ty < 0 || ty > SCREENHEIGHT - 1 \
	|| tx > SCREENWIDTH - 1)
		return (0);
	all->img->data = mlx_get_data_addr(image, &all->img->bpp, \
	&all->img->size_line, &all->img->endian);
	if (!all->img->data)
		clean_win_kill(all);
	dst = all->img->data + (ty * all->img->size_line + tx * \
	(all->img->bpp / 8));
	return (*(int *)dst);
}

void	my_pixel_put(t_algo *algo, t_img *img, int color)
{
	char	*dst;

	if (algo->x < 0 || algo->y < 0 || algo->y > SCREENHEIGHT - 1 \
	|| algo->x > SCREENWIDTH - 1)
		return ;
	dst = img->img_addr + (algo->y * img->line + algo->x * (img->bp / 8));
	*(int *)dst = color;
}

void	my_pixel_put2(int x, int y, t_img *img, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || y > SCREENHEIGHT - 1 \
	|| x > SCREENWIDTH - 1)
		return ;
	dst = img->img_addr + (y * img->line + x * (img->bp / 8));
	*(int *)dst = color;
}

void	put_square(int x, int y, t_struct *all, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			my_pixel_put2(y + j, x + i, all->img, color);
			i++;
		}
		j++;
	}
}

void	ft_mini_map(t_struct *all)
{
	int	x;
	int	y;

	x = 0;
	all->algo->x = 6;
	while (all->data->map[all->algo->x])
	{
		all->algo->y = 0;
		y = 0;
		while (all->data->map[all->algo->x][all->algo->y])
		{
			if (all->data->map[all->algo->x][all->algo->y] == '1')
				put_square(x, y, all, 0x40E0D0);
			if (all->algo->x == (int)all->algo->pos.x
				&& all->algo->y == (int)all->algo->pos.y)
				put_square(x, y, all, 0xFF4500);
			all->algo->y++;
			y += 5;
		}
		all->algo->x++;
		x += 5;
	}
}
