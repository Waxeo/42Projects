/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:42:01 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/19 13:39:03 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h> 

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
//
//int	main()
//{
//	char s[] = "salut bg";
//	int	fd = 1;
//
//	ft_putstr_fd(s, fd);
//}
