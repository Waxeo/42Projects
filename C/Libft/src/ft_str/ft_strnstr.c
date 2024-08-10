/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:11:41 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/27 14:36:08 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!to_find[i])
		return ((char *)str);
	while ((str[i] != '\0') && (i < len))
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
//
//int	main()
//{
//	char c[] = "Call of duty";
//	char d[] = "of";
//	int i = 6;
//
//	printf("%s\n", ft_strnstr(c, d, i));
//	printf("%s\n", strnstr(c, d, i));
//}
