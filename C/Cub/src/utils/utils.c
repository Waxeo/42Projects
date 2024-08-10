/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:44:56 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/09/15 12:42:11 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	kill_da_shit(char *msg, t_struct *all)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	if (all->data->map)
		free_map_tab(all->data->map);
	free(all->data);
	free(all->mlx);
	free(all->algo);
	free(all->img);
	free(all);
	exit(EXIT_FAILURE);
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

int	clean_win_kill(t_struct *all)
{	
	mlx_destroy_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	mlx_destroy_display(all->mlx->mlx_ptr);
	free(all->mlx->mlx_ptr);
	if (all->data->map)
		free_map_tab(all->data->map);
	free(all->mlx);
	free(all->algo);
	free(all->img);
	free(all->data);
	free(all);
	exit(0);
	return (0);
}

float	ft_fabs(float i)
{
	if (i < 0)
		return (i *= -1);
	return (i);
}
