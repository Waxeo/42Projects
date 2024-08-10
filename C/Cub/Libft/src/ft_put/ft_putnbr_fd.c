/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:32 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/11 13:11:25 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n == -2147483648)
	{
		write(fd, "-21", 3);
		write(fd, "47483648", 8);
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd((n + '0'), fd);
}
//
//int	main()
//{
//	int c = -2147483648;
//	int fd = 1;
//
//	ft_putnbr_fd(c, fd);
//}
