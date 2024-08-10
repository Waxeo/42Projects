/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:16:26 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:14 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_da_shit(char *msg, t_data *data)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	if (data->map)
		free_map_tab(data->map);
	free(data);
	exit(EXIT_FAILURE);
}

void	clean_win_kill(t_data *data)
{	
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->p);
	mlx_destroy_image(data->mlx_ptr, data->e);
	mlx_destroy_image(data->mlx_ptr, data->c);
	mlx_destroy_image(data->mlx_ptr, data->w);
	mlx_destroy_image(data->mlx_ptr, data->f);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map_tab(data->map);
	free(data);
	exit(0);
}

void	free_map_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_elem(t_data *data)
{
	data->y = 0;
	while (data->map[data->y])
	{	
		data->x = 0;
		while (data->map[data->y][data->x])
		{
			if ((data->map[data->y][data->x] != '0')
				&& (data->map[data->y][data->x] != '1')
				&& (data->map[data->y][data->x] != 'P')
				&& (data->map[data->y][data->x] != 'E')
				&& (data->map[data->y][data->x] != 'C'))
				kill_da_shit("Wrong Element in Map.\n", data);
			data->x++;
		}
		data->y++;
	}
	return (1);
}

int	arg_error(int argc, char *argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		kill_da_shit("Invalid args number !\n", data);
		return (0);
	}
	while (argv[i])
	{
		if (argv[i] == '.')
		{
			if (argv[i + 1] != 'b' || argv[i + 2] != 'e'
				|| argv[i + 3] != 'r' || argv[i + 4] != '\0')
			{
				kill_da_shit("Please check map name.\n", data);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
