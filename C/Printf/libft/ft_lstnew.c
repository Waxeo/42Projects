/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:35:22 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/15 15:08:55 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pew;

	pew = malloc(sizeof(t_list));
	if (!pew)
		return (NULL);
	pew->content = content;
	pew->next = NULL;
	return (pew);
}
