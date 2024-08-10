/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:41:26 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/17 18:38:12 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_pile	*ft_create_pile(int argc, char **argv, int i, int ref)
{
	t_pile			*pile_a;
	long long int	check;

	pile_a = NULL;
	while (i < argc)
	{
		check = atoi_ft(argv[i]);
		if (i == ref && (check > 2147483647 || check < -2147483648))
			killer(pile_a, argv, ref);
		if (i > ref && (check > 2147483647 || check < -2147483648))
			killer(pile_a, argv, ref);
		if (i == ref)
			pile_a = ft_lstnew((int)check);
		else
			ft_lstadd_back(&pile_a, ft_lstnew((int)check));
		i++;
	}
	return (pile_a);
}

t_pile	*ft_pile_init(int argc, char **argv)
{
	t_pile	*pile_a;
	char	**tab;

	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab[0])
		{
			free(tab);
			killer2();
		}
		if (ft_check_args(tab, 0) != 0)
		{
			pile_a = ft_create_pile(ft_tablen(tab), tab, 0, 0);
			free_arg_tab(tab);
		}
		else
		{
			free_arg_tab(tab);
			killer2();
		}
	}
	if (argc > 2)
	{
		if (ft_check_args(argv, 1) != 0)
			pile_a = ft_create_pile(argc, argv, 1, 1);
		else
			killer2();
	}
	return (pile_a);
}

t_pile	*ft_lstnew(int nbr)
{
	t_pile	*pew;

	pew = malloc(sizeof(t_pile));
	if (!pew)
		return (NULL);
	pew->content = nbr;
	pew->next = NULL;
	return (pew);
}

t_pile	*ft_lstlast(t_pile *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
		return (ft_lstlast(lst->next));
	return (lst);
}

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*buu;

	buu = ft_lstlast(*lst);
	if (!buu)
		*lst = new;
	else
		buu->next = new;
}
