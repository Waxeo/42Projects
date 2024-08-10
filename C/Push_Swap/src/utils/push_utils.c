/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:40:04 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/08 05:09:30 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_put_index(t_pile *pile_a, int *tab, int size)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = pile_a;
	while (pile_a)
	{
		while (i < size)
		{
			if (pile_a->content == tab[i])
			{
				pile_a->index = i;
				pile_a = pile_a->next;
				i = 0;
				break ;
			}
			i++;
		}
	}
	pile_a = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		temp;

	i = 0;
	size--;
	while (i < size)
	{
		while (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		i++;
	}
}

int	ft_lstsize(t_pile *lst)
{
	int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		count++;
	}	
	return (count);
}

void	ft_indexage(t_pile *pile_a)
{
	t_pile	*tmp;
	int		i;
	int		*tab;
	int		size;

	i = 0;
	size = ft_lstsize(pile_a);
	tmp = pile_a;
	tab = malloc(sizeof(t_pile) * size);
	if (!tab)
		return ;
	while (pile_a != NULL)
	{
		tab[i] = pile_a->content;
		pile_a = pile_a->next;
		i++;
	}
	pile_a = tmp;
	ft_sort_int_tab(tab, size);
	ft_put_index(pile_a, tab, size);
	free(tab);
}
