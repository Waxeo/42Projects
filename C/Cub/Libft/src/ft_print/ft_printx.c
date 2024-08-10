/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:49:09 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/22 16:18:39 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_hexa(unsigned int nbr)
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

void	ft_convert(unsigned int nbr, char *base)
{
	while (nbr >= 16)
	{
		ft_convert(nbr / 16, base);
		nbr %= 16;
	}
	ft_putchar_fd(base[nbr], 1);
}

int	ft_printhexa(unsigned int nbr, int type)
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
		ft_convert(nbr, min);
	if (type == 2 && nbr != 0)
		ft_convert(nbr, maj);
	return (ft_len_hexa(nbr));
}
