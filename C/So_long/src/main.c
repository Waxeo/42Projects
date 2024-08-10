/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:58:46 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/18 15:39:53 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_with_mouse(t_data *data)
{
	clean_win_kill(data);
	return (0);
}

int	mlx_initialize(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			ft_strlen(data->map[0]) * 64, len(data->map) * 64, "So_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_memset(data, 0, sizeof(t_data));
	if (ft_map_checking(argc, argv[1], data) == 1)
	{
		if (mlx_initialize(data) != 1)
			kill_da_shit("Mlx init failed\n", data);
		ft_associates(data);
		ft_add_image(data->map, data);
		mlx_hook(data->win_ptr, 2, (1L << 0), &controls_working, data);
		mlx_hook(data->win_ptr, 17, 0, &close_with_mouse, data);
		mlx_loop(data->mlx_ptr);
	}
	return (1);
}
