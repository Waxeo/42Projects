/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:41:39 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/27 15:43:32 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_perror(char *command, t_data *data, char *cdir, int toggle)
{
	ft_putstr_fd("minishell: ", 2);
	perror(command);
	if (cdir)
		free(cdir);
	if (toggle)
		exit(errno);
	else
	{
		data->status = errno;
		return ;
	}	
}

void	handle_error(int n, char *cmd1, char *cmd2, char *error)
{
	if (n)
		ft_putstr_fd("minishell: ", 2);
	if (cmd1)
	{
		ft_putstr_fd(cmd1, 2);
		ft_putstr_fd(": ", 2);
	}
	if (cmd2)
	{
		ft_putstr_fd(cmd2, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(error, 2);
}

int	exit_or_return(int toggle)
{
	if (toggle)
		exit (1);
	else
		return (1);
}
