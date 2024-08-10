/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:53:36 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/01 18:26:28 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*starton( void )
{
	static t_data	data = {0};

	return (&data);
}

static void	launch_mini(t_list *env)
{
	char	*read;

	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, &handler_sig);
		read = readline("Minishell> ");
		if (read == NULL)
		{
			printf("exit\n");
			free_lst(env);
			exit(0);
		}
		if (read[0] != '\0')
		{
			if (pipex(read, env) != -1)
			{
				add_history(read);
				free(read);
			}
		}
		else
			free(read);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_list	*env;

	(void)av;
	rl_outstream = stderr;
	if (ac > 1)
		return (write(2, "Try to launch ./minishell without arguments\n", 20));
	env = env_init(envp);
	get_shlvl(env);
	launch_mini(env);
}
