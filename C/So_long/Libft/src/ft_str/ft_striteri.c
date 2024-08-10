/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:45 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/14 16:17:52 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	if (!s || !f)
		return ;
	while (i < len)
	{
		(*f)(i, s);
		s++;
		i++;
	}
}
