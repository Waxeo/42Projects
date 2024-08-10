/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:50:29 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/22 10:50:29 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*g_env;

void	handler_sig(int sig)
{
	t_data	*data;

	(void)sig;
	data = starton();
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	data->status = 130;
}

void	handler_cmd(int sig)
{
	t_data	*data;

	(void)sig;
	data = starton();
	write(2, "\n", 1);
	data->status = 130;
}

void	child_hd(t_list *env, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!g_env)
		g_env = env;
	signal(SIGINT, &handler_hd);
	while (i < data->here_nb)
	{
		openfileshd(i, data->here);
		i++;
	}
	i = -1;
	while (++i < data->here_nb)
		free(data->here[i].delim);
	free_lst(env);
	free(data->here);
	free_tab(data->av);
	free(data->pid);
	free(data->env);
	exit(0);
}

void	handler_hd(int sig)
{
	t_data	*data;
	int		i;

	(void)sig;
	i = 0;
	data = starton();
	write(2, "\n", 1);
	while (i < data->here_nb)
	{
		safe_close(data->here[i].pipe[0]);
		safe_close(data->here[i].pipe[1]);
		free(data->here[i].delim);
		i++;
	}
	free_tab(data->av);
	free_lst(g_env);
	free(data->env);
	free(data->pid);
	free(data->here);
	exit(130);
}
