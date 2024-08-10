/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:10:24 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/01 14:00:44 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	n1;
	int	n2;

	i = 0;
	n1 = 0;
	n2 = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	if (s1[i] != s2[i])
	{
		n1 = n1 + (s1[i] + '0');
		n2 = n2 + (s2[i] + '0');
	}
	return (n1 - n2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	i = 0;
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	while ((b1[i] != '\0') && (b2[i] != '\0')
		&& (b1[i] == b2[i]) && (i < len - 1))
		i++;
	return (b1[i] - b2[i]);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
		i++;
	return (i);
}
