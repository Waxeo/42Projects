/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:34:36 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/10 16:20:50 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

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
//
//int	main()
//{
//	char str[] = "2147483647";
//	printf("%d\n", atoi(str));
//	printf("%d\n", ft_atoi(str));
//}
