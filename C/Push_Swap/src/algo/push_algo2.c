/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:58:52 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/15 14:50:15 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	mini_algo(t_pile **pile_a)
{
	while (!ft_sort_or_nah(*pile_a))
	{
		if ((*pile_a)->content == get_max(*pile_a))
			ft_ra(pile_a);
		if (ft_lstlast(*pile_a)->content != get_max(*pile_a))
			ft_rra(pile_a);
		if ((*pile_a)->content > (*pile_a)->next->content)
			ft_sa(*pile_a);
	}
	free_lst(pile_a);
}

void	middle_algo(t_pile **pile_a, t_pile **pile_b)
{
	int		i;

	i = 0;
	if (!ft_sort_or_nah(*pile_a))
	{
		if (ft_lstsize(*pile_a) <= 3)
		{
			mini_algo(pile_a);
			return ;
		}
		sort_five(pile_a, pile_b, i);
		mini_algo(pile_a);
		while (*pile_b)
			ft_pp(pile_a, pile_b, 0);
	}
	free_lst(pile_a);
}

void	fat_boi(t_pile **pile_a, t_pile **pile_b)
{
	int	chunk;

	chunk = ft_lstsize(*pile_a) / chose_chunks(ft_lstsize(*pile_a));
	while (ft_lstsize(*pile_a) >= 1)
	{
		while (check_chunk(pile_a, chunk) != 0)
		{
			if (find_top_chunknbr(pile_a, chunk) <= find_else(pile_a, chunk))
				ft_ra(pile_a);
			else
				ft_rra(pile_a);
			if ((*pile_a)->index <= chunk)
			{
				ft_pp(pile_a, pile_b, 1);
				if ((*pile_b)->index <= chunk / 2)
					ft_rb(pile_b);
			}
		}
		ft_indexage(*pile_a);
	}
	ft_pp(pile_a, pile_b, 1);
	ft_indexage(*pile_b);
	we_in_the_a(pile_a, pile_b);
	free_lst(pile_a);
}
