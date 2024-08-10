/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfiles2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:56:38 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/05/18 16:17:36 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*ft_gnljoin(char *s1, char *s2)
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

static	char	*ft_line_return(char *stock)
{
	int		i;
	char	*s;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	s = ft_calloc(sizeof(char), (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		s[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		s[i] = stock[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static	char	*ft_stock(char *stock)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	i = 0;
	j = 0;
	s = NULL;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	s = ft_calloc((ft_strlen(stock) - i + 1), sizeof(char));
	if (!s)
		return (NULL);
	i++;
	while (stock[i])
		s[j++] = stock[i++];
	s[j] = '\0';
	free(stock);
	return (s);
}

static	char	*ft_read_and_save(int fd, char *stock)
{
	char	*buf;
	int		read_bytes;

	read_bytes = 1;
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		stock = ft_gnljoin(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stock)
			free(stock);
		return (0);
	}
	stock = ft_read_and_save(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_line_return(stock);
	stock = ft_stock(stock);
	return (line);
}
