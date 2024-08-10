/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:42:19 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/15 14:52:16 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_chunk(t_pile **pile, int chunk_size)
{
	int		i;
	t_pile	*tmp;

	tmp = *pile;
	i = 0;
	while (tmp)
	{
		if (tmp->index <= chunk_size)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	chose_chunks(int size)
{
	int	chunk;

	if (size <= 10)
		chunk = 2;
	else if (size <= 150)
		chunk = 4;
	else
		chunk = 10;
	return (chunk);
}

int	find_top_chunknbr(t_pile **pile, int chunk_size)
{
	int		place;
	t_pile	*tmp;

	tmp = *pile;
	place = 0;
	while (tmp)
	{
		if (tmp->index <= chunk_size)
			return (place);
		place++;
		tmp = tmp->next;
	}
	return (0);
}

int	find_else(t_pile **pile, int chunk_size)
{
	int		place;
	t_pile	*tmp;

	tmp = *pile;
	place = 0;
	while (tmp)
	{
		if (tmp->index <= chunk_size)
			place = 0;
		tmp = tmp->next;
		place++;
	}
	return (place);
}

void	we_in_the_a(t_pile **pile_a, t_pile **pile_b)
{
	int	place;

	while (*pile_b)
	{
		place = get_max_place(*pile_b, get_max(*pile_b));
		if (place <= ft_lstsize(*pile_b) / 2)
		{
			while (place)
			{
				ft_rb(pile_b);
				place--;
			}
		}
		else
		{
			while (place < ft_lstsize(*pile_b))
			{
				ft_rrb(pile_b);
				place++;
			}
		}
		ft_pp(pile_a, pile_b, 0);
	}
}
