/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:19 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/05/18 11:32:09 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		*(unsigned char *)(ptr + i) = (unsigned char)value;
		i++;
	}
	return (ptr);
}

static	void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return ;
	while (i < n)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*s;

	if ((nbr != 0) && (size != 0) && (nbr * size) / size != nbr)
		return (NULL);
	s = (void *)malloc(nbr * size);
	if (!s || nbr >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	ft_bzero(s, nbr * size);
	return (s);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
	return (s);
}
