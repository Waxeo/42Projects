/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:40:43 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/18 15:13:38 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	ft_checkc(char s, char const *c)
{
	int	j;

	j = 0;
	while (c[j])
	{
		if (c[j] == s)
			return (1);
		j++;
	}	
	return (0);
}

char	*ft_strtrim(char const *s1, char const *c)
{
	unsigned char	*p;
	unsigned char	*b1;
	int				i;
	int				j;
	int				o;

	b1 = (unsigned char *)s1;
	i = ft_strlen(s1);
	j = 0;
	o = 0;
	if (!s1)
		return (NULL);
	while (b1[j] && (ft_checkc(b1[j], c) == 1))
		j++;
	while (i > j && ft_checkc(b1[i - 1], c) == 1)
		i--;
	p = malloc(sizeof(char) * (i - j + 1));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[o++] = b1[j++];
	}
	p[o] = '\0';
	return ((char *)p);
}
//
//int	main()
//{
//	char const *s = "tripouille   xxx";
//	char const *a = " x";
//
//	printf("%s\n", ft_strtrim(s, a));
//}
