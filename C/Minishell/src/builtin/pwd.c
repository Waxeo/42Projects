/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:26:20 by abiddane          #+#    #+#             */
/*   Updated: 2023/06/01 13:57:00 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_cmd(t_data *data, int toggle)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		return ;
	if (getcwd(buf, BUFFER_SIZE) == NULL)
	{
		handle_perror("pwd", data, buf, toggle);
		return ;
	}
	ft_putstr_fd(buf, 1);
	ft_putstr_fd("\n", 1);
	free(buf);
	data->status = 0;
}
