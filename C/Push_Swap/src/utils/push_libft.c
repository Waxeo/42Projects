/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:58:09 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/16 21:54:39 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

long long int	atoi_ft(const char *str)
{
	long long int	i;
	long long int	sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-')
		&& (str[i + 1] >= 48 && str[i + 1] <= 57))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * sign;
	return (res);
}
