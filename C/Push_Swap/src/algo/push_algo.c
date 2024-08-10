/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:56:28 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/09 15:10:19 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_max(t_pile *pile_a)
{
	int	value;

	value = pile_a->content;
	while (pile_a)
	{
		if (value < pile_a->content)
			value = pile_a->content;
		pile_a = pile_a->next;
	}
	return (value);
}

int	get_max_place(t_pile *pile_a, int max)
{
	int	place;

	place = 0;
	while (pile_a->content != max)
	{
		pile_a = pile_a->next;
		place++;
	}
	return (place);
}

int	get_min_place(t_pile *pile_a, int index)
{
	int	place;

	place = 0;
	while (pile_a->index != index)
	{
		pile_a = pile_a->next;
		place++;
	}
	return (place);
}

int	ft_sort_or_nah(t_pile *pile_a)
{
	while (pile_a->next)
	{
		if (pile_a->content > pile_a->next->content)
			return (0);
		pile_a = pile_a->next;
	}
	return (1);
}

void	sort_five(t_pile **pile_a, t_pile **pile_b, int i)
{
	int	place;

	while (i < 2)
	{
		place = get_min_place(*pile_a, i);
		if (place <= ft_lstsize(*pile_a) / 2)
		{
			while (place)
			{
				ft_ra(pile_a);
				place--;
			}
		}
		else
		{
			while (place < ft_lstsize(*pile_a))
			{
				ft_rra(pile_a);
				place++;
			}
		}
		ft_pp(pile_a, pile_b, 1);
		i++;
	}
}
