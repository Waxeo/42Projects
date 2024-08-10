/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfiles.c                     	                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:31 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/27 15:06:00 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	ft_strchr(char *cmd, char c)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i++] == c)
			return (1);
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
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
	while ((b1[i] != '\0')
		&& (b2[i] != '\0')
		&& (b1[i] == b2[i]) && (i < len - 1))
		i++;
	return (b1[i] - b2[i]);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
