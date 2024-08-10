/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:49 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/05/18 14:40:28 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	open_in(t_data *data, char *infile)
{
	data->fdin = open(infile, O_RDWR);
	if (data->fdin < 0)
		file_error(data, infile);
}

void	open_out(t_data *data, char *outfile)
{
	data->fdout = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (data->fdout < 0)
		file_error(data, outfile);
}

void	lim_open(t_data *data)
{
	data->fdin = open("tmpfd.txt", O_TRUNC | O_CREAT | O_RDWR, 0664);
	if (data->fdin < 0)
		file_error(data, "here_doc");
}

void	close_all_sides(t_data *data)
{
	safe_close(data->pipefd[0]);
	safe_close(data->pipefd[1]);
}

void	file_error(t_data *data, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	close_all_sides(data);
	exit(0);
}
