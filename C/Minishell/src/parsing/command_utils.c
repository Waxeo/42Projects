/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:46:24 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/28 12:55:14 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redir(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if ((tab[i][0] == '<' || tab[i][0] == '>')
			&& (!tab[i + 1]))
		{
			ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
			return (1);
		}
	}
	i = -1;
	while (tab[++i])
	{
		if ((tab[i][0] == '<' || tab[i][0] == '>')
			&& (tab[i + 1][0] == '<' || tab[i + 1][0] == '>'))
		{
			ft_putstr_fd("syntax error near unexpected token `", 2);
			ft_putstr_fd(tab[i + 1], 2);
			ft_putstr_fd("\'\n", 2);
			return (1);
		}
	}
	return (0);
}

static char	**tab_delete_redir(char **ret, char **tab)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (tab[++i])
	{
		if ((tab[i][0] == '>' || tab[i][0] == '<') && tab[i + 1])
			i++;
		else
			ret[++j] = ft_strdup(tab[i]);
	}
	ret[++j] = NULL;
	return (ret);
}

char	**delete_redir(char **tab)
{
	char	**ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ret = NULL;
	while (tab[++i])
	{
		if ((tab[i][0] == '>' || tab[i][0] == '<') && tab[i + 1])
			i++;
		else
			j++;
	}
	ret = malloc(sizeof(char *) * (j + 1));
	ret = tab_delete_redir(ret, tab);
	free_tab(tab);
	return (ret);
}
