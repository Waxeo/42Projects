/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:29:03 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/11 12:42:23 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)(p1 + i) != *(unsigned char *)(p2 + i))
			return (*(unsigned char *)(p1 + i) - *(unsigned char *)(p2 + i));
		i++;
	}
	return (0);
}
