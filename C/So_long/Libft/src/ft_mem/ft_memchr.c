/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:45:24 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/14 12:23:50 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < size)
	{
		if ((*(unsigned char *)(s + i)) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
