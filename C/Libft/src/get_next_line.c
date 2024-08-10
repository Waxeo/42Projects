/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:04:35 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/30 15:03:20 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Get_line : sauvegarde de la ligne a return depuis stock vers une chaine "s"
char	*ft_line_return(char *stock)
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

//Save : sauvegarde du reste de la chaine, post \n, pour un nouvel appel a gnl 
char	*ft_stock(char *stock)
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

//lire le fichier txt et récuperer dans stock ce qui est lu tant que pas de \n
char	*ft_read_and_save(int fd, char *stock)
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
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	return (stock);
}

//Gnl : coeur de fonction avec return de la ligne et sauvegarde du reste
char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_read_and_save(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_line_return(stock);
	stock = ft_stock(stock);
	return (line);
}
