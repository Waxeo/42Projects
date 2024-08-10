/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:14:05 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:11 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_opening(char *file, t_data *data)
{
	char	*str;
	char	**tab;
	char	*buf;
	int		fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
		kill_da_shit("File not readable !\n", data);
	str = get_next_line(fd);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		str = ft_strjoin(str, buf);
		free(buf);
	}
	close (fd);
	check_nl(str, data);
	tab = ft_split(str, '\n');
	free(str);
	return (tab);
}

int	len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_check_p(t_data *data)
{
	data->y = 0;
	data->player = 0;
	while (data->map[data->y])
	{	
		data->x = 0;
		while (data->map[data->y][data->x])
		{
			if (data->map[data->y][data->x] == 'P')
				data->player++;
			data->x++;
		}
		data->y++;
	}
	if (data->player < 1)
		kill_da_shit("No Player Found\n", data);
	if (data->player > 1)
		kill_da_shit("Too Much Players\n", data);
	return (1);
}

int	ft_check_e(t_data *data)
{
	data->y = 0;
	data->exit = 0;
	while (data->map[data->y])
	{	
		data->x = 0;
		while (data->map[data->y][data->x])
		{
			if (data->map[data->y][data->x] == 'E')
				data->exit++;
			data->x++;
		}
		data->y++;
	}
	if (data->exit < 1)
		kill_da_shit("No Exit Found\n", data);
	if (data->exit > 1)
		kill_da_shit("Too Much Exits\n", data);
	return (1);
}

int	ft_check_c(t_data *data)
{
	data->y = 0;
	data->collect = 0;
	while (data->map[data->y])
	{	
		data->x = 0;
		while (data->map[data->y][data->x])
		{
			if (data->map[data->y][data->x] == 'C')
				data->collect++;
			data->x++;
		}
		data->y++;
	}
	if (data->collect < 1)
		kill_da_shit("No Collects Founds\n", data);
	return (1);
}
