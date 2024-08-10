/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:36:07 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/10 15:15:59 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stddef.h>

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return ;
	while (i < n)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
}
