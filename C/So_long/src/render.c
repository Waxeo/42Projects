/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:11:08 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:07 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_associates(t_data *data)
{
	int	h;
	int	w;

	data->w = mlx_xpm_file_to_image(data->mlx_ptr, "./img/W.xpm", &w, &h);
	data->f = mlx_xpm_file_to_image(data->mlx_ptr, "./img/F.xpm", &w, &h);
	data->e = mlx_xpm_file_to_image(data->mlx_ptr, "./img/E.xpm", &w, &h);
	data->p = mlx_xpm_file_to_image(data->mlx_ptr, "./img/P.xpm", &w, &h);
	data->c = mlx_xpm_file_to_image(data->mlx_ptr, "./img/C.xpm", &w, &h);
}

void	ft_add_image(char **tab, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '1')
				ft_func_too_long(data, 0, i, j);
			if (tab[j][i] == '0')
				ft_func_too_long(data, 1, i, j);
			if (tab[j][i] == 'P')
				ft_func_too_long(data, 2, i, j);
			if (tab[j][i] == 'E')
				ft_func_too_long(data, 3, i, j);
			if (tab[j][i] == 'C')
				ft_func_too_long(data, 4, i, j);
			i++;
		}
		j++;
	}
}

void	ft_func_too_long(t_data *data, int toggle, int i, int j)
{
	if (toggle == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->w, i * 64, j * 64);
	if (toggle == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->f, i * 64, j * 64);
	if (toggle == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->p, i * 64, j * 64);
	if (toggle == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->e, i * 64, j * 64);
	if (toggle == 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->c, i * 64, j * 64);
}
