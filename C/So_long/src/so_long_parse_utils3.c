/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:16:06 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:16 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_playerx(char **tab, int x)
{
	int	y;

	y = 0;
	while (tab[y])
	{	
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	find_playery(char **tab, int y)
{
	int	x;

	y = 0;
	while (tab[y])
	{	
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_elem_nbr(char **tab)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

char	*ft_fill_one(char *src, int x)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[i])
	{
		if (i != x)
			dest[i] = src[i];
		else
			dest[i] = '1';
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

int	ft_find_path(char **tab, int x, int y, int count)
{
	if (tab[y][x] != '1')
	{
		if (tab[y][x] == 'C' || tab[y][x] == 'E')
			count++;
		tab[y] = ft_fill_one(tab[y], x);
		count = ft_find_path(tab, x + 1, y, count);
		count = ft_find_path(tab, x, y + 1, count);
		count = ft_find_path(tab, x - 1, y, count);
		count = ft_find_path(tab, x, y - 1, count);
	}
	return (count);
}
