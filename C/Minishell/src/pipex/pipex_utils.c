/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:19:59 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/27 14:15:23 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	struct_init(t_data *data, t_list *env, char *read)
{
	data->prev_pipe = -1;
	data->av = split_pipe(read);
	if (!data->av)
		return (1);
	data->nbcmd = tablen(data->av);
	if (data->av)
		data->pid = malloc(sizeof(int) * (data->nbcmd + data->here_doc));
	if (!data->pid)
		return (1);
	data->env = env_tab_init(env);
	data->here_nb = count_hd(read);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**get_cmd_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->env && data->env[i])
	{
		if (!strncmp(data->env[i], "PATH=", 5))
		{
			return (ft_split(data->env[i] + 5, ':'));
		}
		i++;
	}
	return (NULL);
}

char	*cmd_final_state(t_data *data, char *cmd)
{
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) != -1)
			return (cmd);
	}
	data->path = get_cmd_path(data);
	if (!data->path)
		return (NULL);
	while (data->path[i])
	{
		tmp = ft_strjoin(data->path[i], "/");
		new = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(new, F_OK | X_OK) != -1)
			return (new);
		free(new);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
