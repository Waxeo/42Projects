/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:54 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/16 15:59:31 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*s;

	if ((nbr != 0) && (size != 0) && (nbr * size) / size != nbr)
		return (NULL);
	s = (void *)malloc(nbr * size);
	if (!s || nbr >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	ft_bzero(s, nbr * size);
	return (s);
}
