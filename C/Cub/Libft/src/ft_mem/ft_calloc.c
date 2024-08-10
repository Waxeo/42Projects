/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:54 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/09/08 15:43:50 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
