/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:49:22 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/22 10:49:22 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_expand_name(char *str)
{
	int		i;
	char	*var_name;

	i = 0;
	if (ft_isdigit(str[0]) && ft_isdigit(str[i + 1]))
	{
		var_name = malloc(2);
		var_name[0] = str[0];
		var_name[1] = '\0';
		return (var_name);
	}
	while (str[i] && ft_isalnum(str[i]))
		i++;
	var_name = malloc(i + 1);
	if (!var_name)
		return (NULL);
	i = 0;
	while (str[i] && ft_isalnum(str[i]))
	{
		var_name[i] = str[i];
		i++;
	}
	var_name[i] = '\0';
	return (var_name);
}

char	*get_before_expand(char *str, int j)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && i < j)
		i++;
	ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && i < j)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_after_expand(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (str[i] && ft_isalnum(str[i]))
	{
		i++;
		if (ft_isdigit(str[0]) && ft_isdigit(str[1]))
			break ;
	}
	ret = malloc(ft_strlen(str) - i + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		ret[j] = str[i + j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*init_value(t_list *env, char *str, char *name, int *i)
{
	char	*value;

	if (!ft_isalnum(str[*i + 1]))
	{
		value = malloc(2);
		if (!value)
			return (NULL);
		value[0] = '$';
		value[1] = '\0';
		(*i)++;
	}
	else
	{
		if (!search_var(env, name))
		{
			value = malloc(1);
			if (!value)
				return (NULL);
			value[0] = '\0';
		}
		else
			value = get_var_value(search_var(env, name));
	}
	return (value);
}

char	*expand(t_list *env, char *str, t_data *data)
{
	int		i;
	char	*new_str;
	char	*tab[4];

	i = 0;
	while (str[i])
	{
		i = push_to_expand(str, i);
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
				tab_value_err(data, tab, str, i);
			else
				tab_value(env, tab, str, i);
			new_str = ft_strjoin_free(\
					ft_strjoin_free(tab[0], tab[3]), tab[1]);
			i = push_i(env, tab[2], i);
			free_str(str, tab[3], tab[2], tab[1]);
			str = new_str;
		}
	}
	return (str);
}
