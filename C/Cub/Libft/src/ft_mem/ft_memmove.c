/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:10:05 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/10 14:16:21 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)size - 1;
		while ((int)i >= 0)
		{
			(*(char *)(dest + i)) = (*(char *)(src + i));
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			(*(char *)(dest + i)) = (*(char *)(src + i));
			i++;
		}
	}
	return (dest);
}
