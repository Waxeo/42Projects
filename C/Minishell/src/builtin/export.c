/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:26:01 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/30 18:07:00 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_check(char *arg, t_data *data, int toggle)
{
	if (!ft_isalpha(arg[0]) && arg[0] != '\"' && arg[0] != '\''
		&& arg[0] != '_')
	{
		handle_error(1, "export", arg, "not a valid identifier\n");
		exit_or_return(toggle);
		data->status = 1;
		return (1);
	}
	return (0);
}

static t_list	*export_utils(t_list *env, char *arg, t_data *data, int toggle)
{
	char	*name;

	if (export_check(arg, data, toggle))
		return (env);
	name = get_var_name(arg);
	if (name)
	{
		if (!env)
			env = ft_lstnew(arg);
		else if (!search_var(env, name))
			ft_lstadd_back(&env, ft_lstnew(arg));
		else
			modify_var(env, name, arg);
	}
	else if (!name && arg)
	{
		if (!env)
			env = ft_lstnew(arg);
		if (!search_var(env, arg))
			ft_lstadd_back(&env, ft_lstnew(arg));
	}
	free(name);
	data->status = 0;
	return (env);
}

static	t_list	*export_eq(t_list *env, char **cmd, t_data *data, int toggle)
{
	int		i;

	i = 0;
	while (cmd[++i])
		env = export_utils(env, cmd[i], data, toggle);
	return (env);
}

t_list	*export_cmd(t_list *env, t_data *data, char **cmd, int toggle)
{
	if (!cmd[1])
		env_export(env, data);
	else
		env = export_eq(env, cmd, data, toggle);
	return (env);
}
