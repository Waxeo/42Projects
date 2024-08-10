/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:16:30 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/22 16:21:09 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_hexap(unsigned long long nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	ft_convertp(unsigned long long nbr, char *base)
{
	while (nbr >= 16)
	{
		ft_convertp(nbr / 16, base);
		nbr %= 16;
	}
	ft_putchar_fd(base[nbr], 1);
}

int	ft_printhexap(unsigned long long nbr, int type)
{
	char	*maj;
	char	*min;

	min = "0123456789abcdef";
	maj = "0123456789ABCDEF";
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (type == 1 && nbr != 0)
		ft_convertp(nbr, min);
	if (type == 2 && nbr != 0)
		ft_convertp(nbr, maj);
	return (ft_len_hexap(nbr));
}

int	ft_ptr(unsigned long long nbr)
{
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (nbr != 0)
		write(1, "0x", 2);
	return (ft_printhexap(nbr, 1) + 2);
}
