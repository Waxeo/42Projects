/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_doc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:47:02 by abiddane          #+#    #+#             */
/*   Updated: 2023/06/01 10:55:37 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	here_alloc(t_data *data)
{
	data->here = ft_calloc(sizeof(t_here), data->here_nb);
	if (!data->here)
		return (1);
	return (0);
}

void	free_here(t_data *data)
{
	int	i;

	i = 0;
	if (data->here_nb > 0)
	{
		while (i < data->here_nb)
		{
			free(data->here[i].delim);
			i++;
		}
		free(data->here);
	}
}

int	gdelims_aux(t_data *data, char **cmd, int k)
{
	int	j;

	j = -1;
	while (cmd[++j])
	{
		if (!ft_strcmp(cmd[j], "<<"))
		{
			data->here[k].delim = delete_quote(cmd[j + 1], data);
			free(cmd[j]);
			j++;
			pipe(data->here[k].pipe);
			k++;
		}
		else
			free(cmd[j]);
	}
	free(cmd);
	return (k);
}
