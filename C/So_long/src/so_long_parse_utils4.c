/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_utils4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:45:34 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:19 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_replace(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == 'E')
			{
				tab[j] = ft_fill_one(tab[j], i);
				return (tab);
			}
			i++;
		}
		j++;
	}
	return (tab);
}

int	verify_path(char *filename, t_data *data)
{
	int		elem;
	char	**tab;

	tab = ft_opening(filename, data);
	elem = ft_elem_nbr(data->map) + 1;
	data->x = find_playerx(data->map, data->x);
	data->y = find_playery(data->map, data->y);
	data->count = ft_find_path(tab, data->x, data->y, data->count);
	free_map_tab(tab);
	if (data->count != elem)
		kill_da_shit("No Valid Path.\n", data);
	data->count = 0;
	tab = ft_replace(ft_opening(filename, data));
	data->count = ft_find_path(tab, data->x, data->y, data->count);
	free_map_tab(tab);
	if (data->count != elem - 1)
		kill_da_shit("Exit's Blocking Collect.\n", data);
	return (1);
}
