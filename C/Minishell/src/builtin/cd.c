/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:31 by abiddane          #+#    #+#             */
/*   Updated: 2023/05/30 18:06:33 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*get_pwd(t_list *env, char *old, t_data *data, int toggle)
{
	char	*oldpwd;
	char	*pwd;
	char	*buf;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	oldpwd = ft_strjoin("OLDPWD=", old);
	if (!env)
		env = ft_lstnew(oldpwd);
	else if (!search_var(env, "OLDPWD"))
		ft_lstadd_back(&env, ft_lstnew(oldpwd));
	else
		modify_var(env, "OLDPWD=", oldpwd);
	free(oldpwd);
	if (getcwd(buf, BUFFER_SIZE) == NULL)
		return (return_perror(env, data, buf, toggle));
	pwd = ft_strjoin("PWD=", buf);
	if (!search_var(env, "PWD"))
		ft_lstadd_back(&env, ft_lstnew(pwd));
	else
		modify_var(env, "PWD=", pwd);
	free(pwd);
	free(buf);
	return (env);
}

static t_list	*cd_home(t_list *env, char *buf, t_data *data, int toggle)
{
	char	*cdir;
	char	*home;

	if (getcwd(buf, BUFFER_SIZE) == NULL)
		return (return_perror(env, data, NULL, toggle));
	home = search_var(env, "HOME");
	cdir = get_var_value(home);
	if (!home || !cdir)
	{
		error_home(home, cdir, toggle);
		data->status = 1;
		return (env);
	}
	if (chdir(cdir) == -1)
		return (return_perror(env, data, cdir, toggle));
	else
		get_pwd(env, buf, data, toggle);
	free(cdir);
	data->status = 0;
	return (env);
}

static t_list	*cd_old(t_list *env, char *buf, t_data *data, int toggle)
{
	char	*cdir;

	if (getcwd(buf, BUFFER_SIZE) == NULL)
		return (return_perror(env, data, NULL, toggle));
	cdir = get_var_value(search_var(env, "OLDPWD"));
	if (!cdir)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		exit_or_return(toggle);
		data->status = 1;
		return (env);
	}
	if (chdir(cdir) == -1)
		return (return_perror(env, data, cdir, toggle));
	else
		env = get_pwd(env, buf, data, toggle);
	printf("%s\n", cdir);
	free(cdir);
	data->status = 0;
	return (env);
}

static t_list	*cd_rand(t_list *env, char **cmd, t_data *data, int toggle)
{
	char	*cdir;
	char	*buf;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (getcwd(buf, BUFFER_SIZE) == NULL)
		return (return_perror(env, data, NULL, toggle));
	if (cmd[1][0] == '/')
		cdir = ft_strdup(cmd[1]);
	else
		cdir = ft_strjoin_free(ft_strjoin(buf, "/"), (cmd[1]));
	if (chdir(cdir) == -1)
	{
		free(buf);
		return (return_perror(env, data, cdir, toggle));
	}
	else
		env = get_pwd(env, buf, data, toggle);
	free(cdir);
	free(buf);
	data->status = 0;
	return (env);
}

t_list	*cd_cmd(t_list *env, char **cmd, t_data *data, int toggle)
{
	char	*buf;

	if (cmd[1])
	{
		if (cmd[2])
		{
			ft_putstr_fd("minishell: cd: too many arguments\n", 2);
			exit_or_return(toggle);
			data->status = 1;
			return (env);
		}
	}
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (!cmd[1])
		env = cd_home(env, buf, data, toggle);
	else if (cmd[1][0] == '-')
		env = cd_old(env, buf, data, toggle);
	else
		env = cd_rand(env, cmd, data, toggle);
	free(buf);
	return (env);
}
