/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:32:52 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/10 14:16:10 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (NULL);
	while (i < size)
	{
		(*(char *)(dest + i)) = (*(char *)(src + i));
		i++;
	}
	return (dest);
}
