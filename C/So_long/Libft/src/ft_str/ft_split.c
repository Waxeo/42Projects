/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:56:01 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/18 14:48:47 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//count le nombre de string a creer
static int	ft_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

//count la longueur des strings a creer
static int	ft_len_substr(const char *str, char c, int pos)
{
	int	len;

	len = 0;
	while (str[pos] && str[pos] != c)
	{
		len++;
		pos++;
	}
	return (len);
}

//free en cas d'erreur l'ensemble du tableau
static void	ft_free_tab(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

//fonction coeur ft_split
static int	ft_split_aux(char **tabstr, const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (j < ft_count(str, c))
		{
			tabstr[j] = malloc((ft_len_substr(str, c, i) + 1));
			if (!tabstr[j])
			{
				ft_free_tab(tabstr, j);
				return (0);
			}
			ft_strlcpy(tabstr[j], str + i, ft_len_substr(str, c, i) + 1);
			i += ft_len_substr(str, c, i);
			j++;
		}
	}
	tabstr[j] = NULL;
	return (1);
}

//fonction principale
char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		nb_strs;

	if (!s)
		return (NULL);
	nb_strs = ft_count(s, c);
	tab = (char **)malloc((nb_strs + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (ft_split_aux(tab, s, c) == 0)
		return (NULL);
	return (tab);
}
