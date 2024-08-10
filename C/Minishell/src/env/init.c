/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:37:08 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/01 10:48:10 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*env_init(char **envp)
{
	t_list	*env;
	int		i;

	i = 1;
	if (envp[0])
	{
		env = ft_lstnew(envp[0]);
		while (envp[i] != NULL)
		{
			ft_lstadd_back(&env, ft_lstnew(envp[i]));
			i++;
		}
		return (env);
	}
	else
		return (NULL);
}

char	**env_tab_init(t_list *env)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
	if (!tab)
		return (NULL);
	while (env)
	{
		tab[i] = env->var;
		env = env->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	modify_var(t_list *env, char *name, char *var)
{
	t_list	*new;
	int		size;

	size = ft_strlen(name);
	while (env)
	{
		if (!ft_strncmp(name, env->var, size))
		{
			free(env->var);
			env->var = ft_strdup(var);
			return ;
		}
		if (!ft_strncmp(name, env->next->var, size))
			break ;
		env = env->next;
	}
	if (!env)
		return ;
	new = ft_lstnew(var);
	new->next = env->next->next;
	free(env->next->var);
	free(env->next);
	env->next = new;
}

char	*search_var(t_list *env, char *name)
{
	char	*dest;
	int		size;

	size = ft_strlen(name);
	while (env)
	{
		if (!ft_strncmp(name, env->var, size)
			&& (env->var[size] == '=' || env->var[size] == '\0'))
		{
			dest = env->var;
			return (dest);
		}
		env = env->next;
	}
	return (NULL);
}
