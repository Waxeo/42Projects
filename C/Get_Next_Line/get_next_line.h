/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:04:01 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/30 15:00:52 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *stock);
char	*ft_stock(char *stock);
char	*ft_line_return(char *stock);

char	*ft_calloc(size_t nbr, size_t size);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
#endif
