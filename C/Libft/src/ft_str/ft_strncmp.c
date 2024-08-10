/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:14:36 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/14 13:30:39 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	i = 0;
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	while ((b1[i] != '\0')
		&& (b2[i] != '\0')
		&& (b1[i] == b2[i]) && (i < len - 1))
		i++;
	return (b1[i] - b2[i]);
}
//
//int	main()
//{
//	char a[] = "test\200";
//	char b[] = "test\0";
//
//	printf("%d\n", ft_strncmp(b, a, 6));
//	printf("%d\n", strncmp(b, a, 6));
//}
