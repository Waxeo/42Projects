/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:59:21 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/05/28 17:10:10 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
		return (ft_lstlast(lst->next));
	return (lst);
}

t_list	*ft_lstnew(char *str)
{
	t_list	*pew;

	pew = malloc(sizeof(t_list));
	if (!pew)
		return (NULL);
	pew->var = ft_strdup(str);
	pew->next = NULL;
	return (pew);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buu;

	buu = ft_lstlast(*lst);
	if (!buu)
		*lst = new;
	else
		buu->next = new;
}

void	free_lst(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->var);
		free(tmp);
	}
}
