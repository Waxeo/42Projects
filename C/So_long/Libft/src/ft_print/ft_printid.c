/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:51:27 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/21 17:46:11 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int c)
{
	char	*s;

	s = ft_itoa(c);
	if (!s)
		return (-1);
	c = 0;
	while (s[c])
	{
		ft_putchar_fd(s[c], 1);
		c++;
	}
	free(s);
	return (c);
}

int	ft_print_unsigned(unsigned int c)
{
	if (c >= 10)
		return (ft_print_unsigned(c / 10) + ft_putchar_c((c % 10) + '0'));
	return (ft_putchar_c((c % 10) + '0'));
}
