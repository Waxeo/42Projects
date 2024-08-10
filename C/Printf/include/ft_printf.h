/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:17 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/22 16:24:36 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_check_format(char *format, va_list args);
int		ft_check_arg(char *format, int i, va_list args);

int		ft_putchar_c(char c);
int		ft_string(char *s);

int		ft_ptr(unsigned long long nbr);
int		ft_printhexap(unsigned long long nbr, int type);
void	ft_convertp(unsigned long long nbr, char *base);
int		ft_len_hexap(unsigned long long nbr);

int		ft_print_int(int c);
int		ft_print_unsigned(unsigned int c);

int		ft_printhexa(unsigned int nbr, int type);
void	ft_convert(unsigned int nbr, char *type);
int		ft_len_hexa(unsigned int nbr);

#endif
