/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_pile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:38:27 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/08 05:10:48 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rev_rotate_pile(t_pile **pile)
{
	t_pile	*head;
	t_pile	*tail;
	t_pile	*tmp;

	head = *pile;
	tail = ft_lstlast(*pile);
	tmp = *pile;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tail->next = head;
	*pile = tail;
	tmp->next = NULL;
}

void	ft_rra(t_pile **pile_a)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	ft_rev_rotate_pile(pile_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_pile **pile_b)
{
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	ft_rev_rotate_pile(pile_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	ft_rev_rotate_pile(pile_a);
	ft_rev_rotate_pile(pile_b);
	write(1, "rrr\n", 4);
}
