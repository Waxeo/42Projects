/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:18:15 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/11/15 19:01:43 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*temp2;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	temp2 = new;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		temp2->next = temp;
		temp2 = temp;
		lst = lst->next;
	}
	return (new);
}
