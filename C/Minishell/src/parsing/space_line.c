/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:56:09 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/23 13:44:30 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_sep(char *str, int i)
{
	if (ft_strchr("<>|", str[i]) && !is_in_quote(str, i))
		return (1);
	else
		return (0);
}

static char	*space_alloc(char *str)
{
	char	*ret;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_sep(str, i))
			count++;
		i++;
	}
	ret = malloc(count * 2 + i + 1);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*new_line(char *read)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(read);
	while (read[i])
	{
		if (is_sep(read, i))
		{
			new[j++] = ' ';
			new[j++] = read[i++];
			if ((read[i - 1] == '<' && read[i] == '<')
				|| (read[i - 1] == '>' && read[i] == '>'))
				new[j++] = read[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = read[i++];
	}
	new[j] = '\0';
	return (new);
}
