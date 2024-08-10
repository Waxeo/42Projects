/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:19:51 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/18 15:11:48 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = 11;
	if (n < 0 && n != -2147483648)
	{
		count = 1;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

static void	ft_rev_char_tab(char *tab, int size, int neg)
{
	int	i;
	int	temp;

	i = 0;
	size--;
	if (neg == 1)
		i = 1;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
		i++;
		size--;
	}
}

static char	*ft_putnbr(char *s, int n, int neg, int count)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		s[i] = '-';
		i++;
		neg = 1;
	}
	while (n > 9)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (n >= 0 && n <= 9)
	{
		s[i] = n + '0';
		i++;
	}
	ft_rev_char_tab(s, count, neg);
	return (s);
}

static char	*ft_minbr(char *s)
{
	s[0] = '-';
	s[1] = 2 + '0';
	s[2] = 1 + '0';
	s[3] = 4 + '0';
	s[4] = 7 + '0';
	s[5] = 4 + '0';
	s[6] = 8 + '0';
	s[7] = 3 + '0';
	s[8] = 6 + '0';
	s[9] = 4 + '0';
	s[10] = 8 + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		count;
	int		neg;

	neg = 0;
	count = ft_nbrlen(n);
	s = malloc(sizeof(char) * count + 1);
	if (!s)
		return (NULL);
	if (n != -2147483648)
	{
		ft_putnbr(s, n, neg, count);
		s[count] = 0;
	}
	else
	{
		ft_minbr(s);
		s[count - 1] = 0;
	}
	return (s);
}
//int    main()
//{
//    int    c = -2147483648;
//
//   printf("%s\n", ft_itoa(c));
//}
