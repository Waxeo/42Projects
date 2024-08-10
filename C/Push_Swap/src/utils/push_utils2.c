/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:07:34 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/16 22:01:47 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	killer(t_pile *pile_a, char **tab, int ref)
{
	write(2, "Error\n", 6);
	if (ref == 0)
	{
		if (tab)
			free_arg_tab(tab);
	}
	if (pile_a)
		free_lst(&pile_a);
	exit(EXIT_FAILURE);
}

void	killer2(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_arg_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_lst(t_pile **pile)
{
	t_pile	*tmp;

	while (*pile)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		free(tmp);
	}
}
