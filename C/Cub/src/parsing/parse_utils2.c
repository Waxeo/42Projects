/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:46:07 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/09/14 16:36:15 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	find_playerx(char **tab)
{
	double	y;
	double	x;
	char	*finder;

	x = 6;
	finder = "NESW";
	while (tab[(int)x])
	{	
		y = 0;
		while (tab[(int)x][(int)y])
		{
			if (ft_strchr(finder, tab[(int)x][(int)y]))
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

double	find_playery(char **tab)
{
	double	y;
	double	x;
	char	*finder;

	x = 6;
	finder = "NESW";
	while (tab[(int)x])
	{	
		y = 0;
		while (tab[(int)x][(int)y])
		{
			if (ft_strchr(finder, tab[(int)x][(int)y]))
				return (y);
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_check_textures(t_struct *all, char **tab)
{
	if (!ft_strncmp(tab[0], "NO", 3))
		all->data->no++;
	else if (!ft_strncmp(tab[0], "SO", 3))
		all->data->so++;
	else if (!ft_strncmp(tab[0], "WE", 3))
		all->data->we++;
	else if (!ft_strncmp(tab[0], "EA", 3))
		all->data->ea++;
	else
		kill_da_shit("Problem in textures infos.\n", all);
	if (open(tab[1], O_RDWR) == -1)
		kill_da_shit("Problem in textures infos.\n", all);
	return ;
}

void	take_rgb(char **rgb, char **tab, t_data *data)
{
	data->r = ft_atoi(rgb[0]);
	data->g = ft_atoi(rgb[1]);
	data->b = ft_atoi(rgb[2]);
	if (tab[0][0] == 'F')
		data->frgb = (data->r << 16) | (data->g << 8 | data->b);
	else if (tab[0][0] == 'C')
		data->crgb = (data->r << 16) | (data->g << 8 | data->b);
}

void	ft_check_rgb(t_struct *all, char **tab)
{
	int		bgr;
	int		i;
	char	**rgb;

	bgr = 0;
	if (tab[0][0] == 'F')
		all->data->f++;
	else if (tab[0][0] == 'C')
		all->data->c++;
	else
		kill_da_shit("Problem in rgb declaration.\n", all);
	rgb = ft_split(tab[1], ',');
	if (tablen(rgb) != 3)
		kill_da_shit("Problem in rgb declaration.\n", all);
	i = -1;
	while (++i < 3)
	{
		if (ft_strlen(rgb[i]) > 3)
			kill_da_shit("Problem in rgb declaration.\n", all);
		bgr = ft_atoi(rgb[i]);
		if (bgr < 0 || bgr > 255)
			kill_da_shit("Problem in rgb declaration.\n", all);
	}
	take_rgb(rgb, tab, all->data);
	free_tab(rgb);
}
