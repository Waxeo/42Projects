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

#include "../../include/pipex.h"

void	struct_init(t_data *data, int ac, char **av, char **env)
{
	ft_memset(data, 0, sizeof(t_data));
	data->nbcmd = ac - 3;
	data->prev_pipe = -1;
	data->infile = av[1];
	data->outfile = av[ac -1];
	data->env = env;
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

int	check_cmd(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (1);
		i++;
	}
	return (0);
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
