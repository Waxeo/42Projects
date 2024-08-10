/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:12:06 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/17 14:46:23 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_checklen(char *argv)
{
	if (!argv)
		return (0);
	if (ft_strlen(argv) == 0 || ft_strlen(argv) > 10)
		return (0);
	return (1);
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

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
