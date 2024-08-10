/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:18:28 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/22 16:17:06 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{	
		while (s[i])
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	return (i);
}
