/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:01:35 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/27 10:40:24 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	return (NULL);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_str_isdigit(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 1);
		s1[0] = '\0';
	}
	s = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1);
	return (s);
}
