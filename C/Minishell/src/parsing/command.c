/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:49:12 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/22 10:49:12 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_space(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '|' && !is_in_quote(str, i))
		{
			j = i + 1;
			while (str[j] != '|')
			{
				if (str[j] == ' ')
					j++;
				else
					break ;
			}
			if (str[j] == '|')
			{
				ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
				return (1);
			}
		}
	}
	return (0);
}

char	**split_pipe(char *str)
{
	char	**tab;

	if (only_space(str))
	{
		free(str);
		return (NULL);
	}
	str = new_line(str);
	str = parse_quote(str);
	tab = ft_split(str, '|');
	free(str);
	return (tab);
}

char	**final_state(t_list *env, char **tab, t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] < 0)
				tab[i][j] = -tab[i][j];
		}
		tab[i] = expand(env, tab[i], data);
	}
	return (tab);
}

char	**start_cmd_tab(t_data *data, t_list *env, char *str, int toggle)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(str, ' ');
	tab = final_state(env, tab, data);
	if (toggle)
	{
		if (check_redir(tab))
		{
			close_all_sides(data);
			free_tab(tab);
			return (NULL);
		}
		redir_finder(data, env, tab, toggle);
	}
	tab = delete_redir(tab);
	if (!tab[0])
	{
		free(tab);
		return (NULL);
	}
	while (tab[++i])
		tab[i] = delete_quote(tab[i], data);
	return (tab);
}
