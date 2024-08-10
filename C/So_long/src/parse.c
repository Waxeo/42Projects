/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:04:42 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:03 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_nl(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		free(str);
		kill_da_shit("Empty line before the map\n", data);
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			free(str);
			kill_da_shit("Empty new line spotted\n", data);
		}
		i++;
	}
	if (str[i - 1] == '\n')
	{
		free(str);
		kill_da_shit("Empty line after the map\n", data);
	}
	return (1);
}

int	ft_check_border(t_data *data)
{
	int	i;

	data->y = len(data->map) - 1;
	data->x = 0;
	while (data->map[0][data->x])
	{
		if (data->map[0][data->x] != '1'
			|| data->map[data->y][data->x] != '1')
			kill_da_shit("Upper Wall Open.\n", data);
		data->x++;
	}
	i = 0;
	while (i < data->y)
	{
		if (data->map[i][0] != '1'
			|| data->map[i][data->x - 1] != '1')
			kill_da_shit("Side Wall Open.\n", data);
		i++;
	}
	return (1);
}

int	ft_check_pec(t_data *data)
{
	if (!ft_check_p(data))
		return (0);
	if (!ft_check_e(data))
		return (0);
	if (!ft_check_c(data))
		return (0);
	return (1);
}

int	ft_rectangular(t_data *data)
{
	int	i;

	if (!data->map[0] || !data->map[1] || !data->map[2])
		kill_da_shit("Map is Less than 3 lines.\n", data);
	i = 1;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != ft_strlen(data->map[i - 1]))
			kill_da_shit("Map is not Rectangular.\n", data);
		i++;
	}
	return (1);
}

int	ft_map_checking(int ac, char *filename, t_data *data)
{
	if (!arg_error(ac, filename, data))
		return (arg_error(ac, filename, data));
	data->map = ft_opening(filename, data);
	if (!ft_rectangular(data))
		return (ft_rectangular(data));
	if (!ft_elem(data))
		return (ft_elem(data));
	if (!ft_check_pec(data))
		return (ft_check_pec(data));
	if (!ft_check_border(data))
		return (ft_check_border(data));
	if (!verify_path(filename, data))
		return (verify_path(filename, data));
	return (1);
}
