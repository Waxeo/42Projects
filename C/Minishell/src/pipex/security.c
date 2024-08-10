/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:01:05 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/01 16:08:13 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	safe_piping(int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("pipefd");
		return (-1);
	}
	return (0);
}

void	safe_exe(t_data *data, char **cmd, char **env)
{
	if (execve(data->cmd, cmd, env) == -1)
	{
		perror("exceve");
		exit(errno);
	}
}

void	safe_close(int fd)
{
	if (close(fd) == -1)
	{
		perror("close");
		exit(errno);
	}
}

void	safe_dup(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		perror("dup2");
		exit(errno);
	}
}
