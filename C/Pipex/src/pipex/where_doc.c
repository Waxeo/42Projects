/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:39:48 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/05/18 15:29:38 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	limiter_child(t_data *data, char *limiter)
{
	char	*read;
	char	*lim;

	read = NULL;
	lim = ft_strjoin(limiter, "\n");
	if (!lim)
		exit(2);
	lim_open(data);
	while (1)
	{
		write(0, "> ", 2);
		read = get_next_line(0);
		if (!read || !ft_strncmp(read, lim, ft_strlen(lim)))
			break ;
		write(data->fdin, read, ft_strlen(read));
		free(read);
	}
	free(lim);
	free(read);
	get_next_line(-1);
	safe_close(data->fdin);
	data->fdin = 0;
}
