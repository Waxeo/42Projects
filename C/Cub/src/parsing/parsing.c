/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:04:42 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/09/15 15:03:38 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_nl(char *str, t_struct *all)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if ((str[i] == '\n')
			&& (str[i + 1] == '0' || str[i + 1] == '1' || str[i] == ' '))
			break ;
		i++;
	}
	while (str[i + 1])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			kill_da_shit("Empty new line spotted\n", all);
		}
		i++;
	}
	return ;
}

void	ft_elem(t_struct *all)
{
	int		max;
	char	*finder;
	char	*player;

	all->data->y = 6;
	max = tablen(all->data->map);
	finder = "01NSEW ";
	player = "NSEW";
	while (all->data->y < max)
	{	
		all->data->x = 0;
		while (all->data->map[all->data->y][all->data->x])
		{
			if (!ft_strchr(finder, all->data->map[all->data->y][all->data->x]))
				kill_da_shit("Wrong Element in Map.\n", all);
			if (ft_strchr(player, all->data->map[all->data->y][all->data->x]))
				all->data->p++;
			all->data->x++;
		}
		all->data->y++;
	}
	if (all->data->p != 1)
		kill_da_shit("Player problem.\n", all);
	return ;
}

void	info_error(char **tab, t_struct *all)
{
	free_tab(tab);
	kill_da_shit("Problem in map infos.\n", all);
}

void	get_infos(t_struct *all)
{
	int		y;
	char	**tab;

	y = 0;
	while (y < 6)
	{
		tab = ft_split(all->data->map[y], ' ');
		if (tablen(tab) != 2)
			info_error(tab, all);
		if (!ft_strncmp(tab[0], "NO", 3) || !ft_strncmp(tab[0], "SO", 3)
			|| !ft_strncmp(tab[0], "WE", 3) || !ft_strncmp(tab[0], "EA", 3))
			ft_check_textures(all, tab);
		else if (!ft_strncmp(tab[0], "F", 2) || !ft_strncmp(tab[0], "C", 2))
			ft_check_rgb(all, tab);
		else
			info_error(tab, all);
		y++;
		free_tab(tab);
	}
	if (all->data->c != 1 || all->data->f != 1 || all->data->no != 1
		|| all->data->so != 1 || all->data->we != 1 || all->data->ea != 1)
		kill_da_shit("Missing infos.\n", all);
	return ;
}

int	ft_map_checking(int ac, char *filename, t_struct *all)
{		
	arg_error(ac, filename, all);
	all->data->map = ft_opening(filename, all);
	get_infos(all);
	ft_elem(all);
	return (0);
}
