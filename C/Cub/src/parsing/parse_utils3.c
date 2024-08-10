/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:48:51 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/09/15 15:52:34 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	big_length(char **tmp)
{
	int	len;
	int	y;

	y = 6;
	if (tmp[y])
		len = ft_strlen(tmp[y]);
	while (tmp[y])
	{
		if (ft_strlen(tmp[y]) > len)
			len = ft_strlen(tmp[y]);
		y++;
	}
	return (len);
}

char	*fake_cpy(char *old, int len)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (old[i])
	{
		ret[i] = old[i];
		i++;
	}
	while (i < len)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**fill_space(char **tmp)
{
	int		y;
	int		i;
	int		len;
	char	**ret;

	y = 0;
	i = 6;
	len = big_length(tmp);
	ret = malloc(sizeof(char *) * (tablen(tmp) - 5));
	while (i < tablen(tmp))
	{
		ret[y] = fake_cpy(tmp[i], len);
		y++;
		i++;
	}
	ret[y] = NULL;
	return (ret);
}

int	security_map(char **map, int y, int i)
{
	char	*find;

	find = "1 ";
	if (i != 0)
	{
		if (!ft_strchr(find, map[y][i - 1]))
			return (0);
	}
	if (i < ft_strlen(map[0]) - 1)
	{
		if (!ft_strchr(find, map[y][i + 1]))
			return (0);
	}
	if (y != 0)
	{
		if (!ft_strchr(find, map[y - 1][i]))
			return (0);
	}
	if (y < tablen(map) - 1)
	{
		if (!ft_strchr(find, map[y + 1][i]))
			return (0);
	}
	return (1);
}

int	check_map(char **map)
{
	int	i;
	int	y;

	y = 0;
	while (map[y])
	{
		i = 0;
		while (map[y][i])
		{
			if (map[y][i] == ' ')
				if (!security_map(map, y, i))
					return (-1);
			i++;
		}
		y++;
	}
	if (!check_border(map))
		return (-1);
	return (0);
}
