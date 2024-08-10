/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:48:44 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/14 13:23:01 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*b;
	size_t			i;
	size_t			n;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	b = malloc((len + 1) * sizeof(char));
	if (!b)
		return (NULL);
	while (s[i])
	{
		if (i >= start && n < len)
		{
			b[n] = s[i];
			n++;
		}
		i++;
	}
	b[n] = '\0';
	return (b);
}
//
//int	main()
//{
//	char s[] = "42";
//	int	a = 0;
//	size_t	c = 0;
//
//	printf("%s\n", ft_substr(s, a, c));
//}
