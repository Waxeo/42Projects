/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:50:42 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/22 10:48:33 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str || !ft_strchr(str, '='))
		return (NULL);
	while (str[i] != '=')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '=')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_var_value(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !ft_strchr(str, '='))
		return (NULL);
	while (str[i] != '=')
		i++;
	i++;
	dest = malloc(ft_strlen(str) - i + 1);
	if (!dest)
		return (NULL);
	while (str[i + j])
	{
		dest[j] = str[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}
