/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:15:41 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/22 16:19:58 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = ft_check_format(((char *)format), args);
	va_end(args);
	return (i);
}

int	ft_check_format(char *format, va_list args)
{
	int	i;
	int	len;
	int	j;
	int	endlen;

	i = 0;
	j = 0;
	len = 0;
	endlen = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = ft_check_arg(((char *)format), i + 1, args);
			if (len == -1)
				return (-1);
			endlen += len;
			j += 2;
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (i - j + endlen);
}

int	ft_check_arg(char *format, int i, va_list args)
{
	if (format[i] == 'c')
		return (ft_putchar_c((char)va_arg(args, int)));
	if (format[i] == 's')
		return (ft_string((char *)va_arg(args, char *)));
	if (format[i] == 'p')
		return (ft_ptr((unsigned long long)va_arg(args, unsigned long long)));
	if (format[i] == 'd' || format[i] == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (format[i] == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (format[i] == 'x')
		return (ft_printhexa(((unsigned int)va_arg(args, unsigned int)), 1));
	if (format[i] == 'X')
		return (ft_printhexa(((unsigned int)va_arg(args, unsigned int)), 2));
	if (format[i] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}
