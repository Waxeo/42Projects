/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:07:43 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/10 14:15:37 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <unistd.h>
#include <stddef.h>

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
