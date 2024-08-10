/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:05:06 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/09 17:21:54 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_push_pile(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (*pile_a == NULL)
		return ;
	tmp = *pile_a;
	*pile_a = tmp->next;
	tmp->next = *pile_b;
	*pile_b = tmp;
}

void	ft_pp(t_pile **pile_a, t_pile **pile_b, int toggle)
{
	if (toggle == 0)
	{
		if (*pile_b == NULL)
			return ;
		ft_push_pile(pile_b, pile_a);
		write(1, "pa\n", 3);
	}
	else
	{
		if (*pile_a == NULL)
			return ;
		ft_push_pile(pile_a, pile_b);
		write(1, "pb\n", 3);
	}
}

//0 = b to a
//1 = a to b