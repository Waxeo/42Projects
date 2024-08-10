/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 04:01:51 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/08 05:10:15 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rotate_pile(t_pile **pile)
{
	t_pile	*head;
	t_pile	*tail;

	tail = ft_lstlast(*pile);
	head = *pile;
	*pile = (*pile)->next;
	head->next = NULL;
	tail->next = head;
}

void	ft_ra(t_pile **pile_a)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	ft_rotate_pile(pile_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_pile **pile_b)
{
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	ft_rotate_pile(pile_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	ft_rotate_pile(pile_a);
	ft_rotate_pile(pile_b);
	write(1, "rr\n", 3);
}

// void ft_test_rotate_pile(t_pile *pile)
// {
// 	t_pile *curr;
// 	int prev;
// 	int first;

// 	if (pile == NULL)
// 		return ;
// 	curr = pile;
// 	first = curr->content;
// 	prev = curr->content;
// 	curr = curr->next;
// 	while (curr)
// 	{
// 		if (prev < curr->content)
// 			printf("La rotation de la pile n'a pas fonctionné correctement.\n");
// 		prev = curr->content;
// 		curr = curr->next;
// 	}
// 	if (first > prev)
// 		printf("La rotation de la pile n'a pas fonctionné correctement.\n");
// 	else
// 		printf("La rotation de la pile a fonctionné correctement.\n");
// }
