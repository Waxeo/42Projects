/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:50:45 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/05/18 15:55:40 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

// ./pipex Makefile <cat || <ls grep "wc -l"  >|| lsblk> outfile

void	redirection(t_data *data, int i)
{
	if (i == 0)
	{
		open_in(data, data->infile);
		safe_dup(data->fdin, STDIN_FILENO);
		safe_close(data->fdin);
	}
	if (i == data->nbcmd - 1)
	{
		open_out(data, data->outfile);
		safe_dup(data->fdout, STDOUT_FILENO);
		safe_close(data->fdout);
	}
	if (i != 0)
	{
		safe_dup(data->prev_pipe, STDIN_FILENO);
		safe_close(data->prev_pipe);
	}
	if (i != data->nbcmd - 1)
		safe_dup(data->pipefd[1], STDOUT_FILENO);
	close_all_sides(data);
}

void	here_doc_redir(t_data *data, int i)
{
	if (i == 1)
	{
		data->fdin = open("tmpfd.txt", O_RDWR);
		safe_dup(data->fdin, STDIN_FILENO);
		safe_close(data->fdin);
	}
	if (i == data->nbcmd)
	{
		open_out(data, data->outfile);
		safe_dup(data->fdout, STDOUT_FILENO);
		safe_close(data->fdout);
	}
	if (i != 1)
	{
		safe_dup(data->prev_pipe, STDIN_FILENO);
		safe_close(data->prev_pipe);
	}
	if (i != data->nbcmd)
		safe_dup(data->pipefd[1], STDOUT_FILENO);
	close_all_sides(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac < 5)
		return (1);
	struct_init(&data, ac, av, env);
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		data.here_doc = 1;
		i++;
		data.nbcmd--;
		limiter_child(&data, av[2]);
	}
	data.pid = malloc(sizeof(int) * (data.nbcmd + data.here_doc));
	while (i < data.nbcmd + data.here_doc)
	{
		safe_piping(data.pipefd);
		data.pid[i] = fork();
		if (data.pid[i] == 0)
		{
			free(data.pid);
			if (!data.here_doc)
				redirection(&data, i);
			else
				here_doc_redir(&data, i);
			if (check_cmd(av[i + 2]))
			{
				data.cmd_options = ft_split(av[i + 2], ' ');
				data.cmd = cmd_final_state(&data, data.cmd_options[0]);
				if (data.cmd)
					safe_exe(&data, env);
				free_tab(data.cmd_options);
				free_tab(data.path);
				if (data.cmd)
					free(data.cmd_options);
			}
			ft_putstr_fd(av[i + 2], STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(127);
		}
		else if ((data.pid[i] > 0 && !data.here_doc)
			|| (data.pid[i] > 1 && data.here_doc))
		{
			safe_close(data.pipefd[1]);	
			if (data.prev_pipe != -1)
				safe_close(data.prev_pipe);
			data.prev_pipe = data.pipefd[0];
		}
		i++;
	}
	safe_close(data.pipefd[0]);
	while (i < ac)
	{
		waitpid(-1, &data.status, 0);
		i++;
	}
	if (data.here_doc)
	{
		waitpid(-1, &data.status, 0);
		unlink("tmpfd.txt");
	}
	free(data.pid);
	return (WEXITSTATUS(data.status));
}