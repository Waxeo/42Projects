/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:41:58 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/15 15:32:40 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_doubles(char **tab, int type)
{
	int	i;
	int	j;

	i = type;
	while (tab[i])
	{
		j = type;
		while (tab[j])
		{
			if (atoi_ft(tab[i]) == atoi_ft(tab[j]) && (i != j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_args(char **tab, int type)
{
	int		i;
	int		j;

	i = type;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (((tab[i][j] != '+' && tab[i][j] != '-') &&
				(tab[i][j] < 48 || tab[i][j] > 57)))
				return (0);
			if ((tab[i][j] == '+' || tab[i][j] == '-') && (j != 0))
				return (0);
			j++;
		}
		i++;
	}
	if (ft_check_doubles(tab, type) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
	if (argc > 1)
	{
		pile_a = ft_pile_init(argc, argv);
		ft_indexage(pile_a);
		if (ft_lstsize(pile_a) <= 5)
		{
			middle_algo(&pile_a, &pile_b);
			return (1);
		}
		else
		{
			fat_boi(&pile_a, &pile_b);
			return (1);
		}
	}
	return (0);
}
