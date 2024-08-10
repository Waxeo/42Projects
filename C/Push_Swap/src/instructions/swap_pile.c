/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:52 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/08 05:11:04 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_swap_pile(t_pile **pile)
{
	int	tmp;
	int	tmp2;

	tmp = (*pile)->content;
	tmp2 = (*pile)->index;
	(*pile)->content = (*pile)->next->content;
	(*pile)->index = (*pile)->next->index;
	(*pile)->next->content = tmp;
	(*pile)->next->content = tmp;
	(*pile)->next->index = tmp2;
	(*pile)->next->index = tmp2;
}

void	ft_sa(t_pile *pile_a)
{
	if (!pile_a || pile_a->next == NULL)
		return ;
	ft_swap_pile(&pile_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_pile *pile_b)
{
	if (!pile_b || pile_b->next == NULL)
		return ;
	ft_swap_pile(&pile_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_pile *pile_a, t_pile *pile_b)
{
	if (!pile_a || pile_a->next == NULL)
		return ;
	if (!pile_b || pile_b->next == NULL)
		return ;
	ft_swap_pile(&pile_a);
	ft_swap_pile(&pile_b);
	write(1, "ss\n", 3);
}
