/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:31:34 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/27 18:21:00 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quote(char *str, t_data *data)
{
	int	i;
	int	comp;
	int	comp2;

	comp = 0;
	comp2 = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && comp2 % 2 == 0)
			comp++;
		if (str[i] == '\'' && comp % 2 == 0)
			comp2++;
		i++;
	}
	if (comp % 2 != 0 || comp2 % 2 != 0)
	{
		handle_error(1, NULL, NULL, "Syntax error : Quote not closed\n");
		data->status = 1;
		return (-1);
	}
	return (comp + comp2);
}

int	is_in_quote(char *str, int n)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i] && i < n)
	{
		if (str[i] == '\"' && quote == 0)
			quote = 1;
		else if (str[i] == '\'' && quote == 0)
			quote = 2;
		else if (str[i] == '\"' && quote == 1)
			quote = 0;
		else if (str[i] == '\'' && quote == 2)
			quote = 0;
		i++;
	}
	return (quote);
}

char	*parse_quote(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_in_quote(str, i) && (str[i] == '|' || str[i] == ' '))
			str[i] = -str[i];
	}
	return (str);
}

char	*delete_quote(char *str, t_data *data)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ret = malloc((ft_strlen(str) - count_quote(str, data) + 1));
	if (!ret)
		return (NULL);
	while (str[++i])
	{
		while ((is_in_quote(str, i) == 1 || is_in_quote(str, i) == 0)
			&& str[i] == '\"')
			i++;
		while ((is_in_quote(str, i) == 2 || is_in_quote(str, i) == 0)
			&& str[i] == '\'')
			i++;
		if (!str[i])
			break ;
		ret[j++] = str[i];
	}
	ret[j] = '\0';
	free(str);
	return (ret);
}
