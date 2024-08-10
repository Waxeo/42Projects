/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:50:48 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/22 10:50:48 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str(char *cmd, char *value, char *name, char *after)
{
	free(value);
	free(name);
	free(cmd);
	free(after);
}

int	push_i(t_list *env, char *name, int i)
{
	if (!name[0])
		return (i + 1);
	else if (!search_var(env, name))
		return (i);
	else
		return (i + ft_strlen(name));
}

void	tab_value_err(t_data *data, char **tab, char *str, int i)
{
	tab[0] = get_before_expand(str, i);
	tab[1] = get_after_expand(str + i + 2);
	tab[2] = get_expand_name(str + i + 1);
	tab[3] = ft_itoa(data->status);
}

void	tab_value(t_list *env, char **tab, char *str, int i)
{
	tab[0] = get_before_expand(str, i);
	tab[1] = get_after_expand(str + i + 1);
	tab[2] = get_expand_name(str + i + 1);
	tab[3] = init_value(env, str, tab[2], &i);
}

int	push_to_expand(char *str, int i)
{
	while (str[i] && str[i] != '$')
	{
		i++;
		if (is_in_quote(str, i) == 2 && str[i] == '$')
			i++;
	}
	return (i);
}
