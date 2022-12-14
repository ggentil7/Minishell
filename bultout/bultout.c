/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:46:16 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:58:21 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**conv_path(t_pars *pars, t_node *env)
{
	char	*path;
	char	**path_t;
	char	*path_tab_tmp;
	int		y;

	(void)pars;
	y = 0;
	if (search_env(env, "PATH") == NULL)
		return (NULL);
	path = search_env(env, "PATH");
	while (path[y] != '=')
	{
		if (path[y] == '\0')
			return (0);
		y++;
	}
	path_t = ft_split(path, ':');
	path_tab_tmp = path_t[0];
	path_t[0] = ft_substr(path_t[0], y + 1, (int)ft_strlen(path_t[0]) + 1);
	free (path_tab_tmp);
	return (path_t);
}

int	exec_bultout_2(t_pars *pars, char **path_tab, char **env)
{
	int		y;
	int		i;
	char	*cmd_path;
	char	*start_cmd_path;

	y = -1;
	i = 0;
	while (path_tab[++y])
	{
		start_cmd_path = ft_strjoin(path_tab[y], "/");
		cmd_path = ft_strjoin(start_cmd_path, pars->cmd);
		free (start_cmd_path);
		if (!access(cmd_path, X_OK))
		{
			if (execve(cmd_path, pars->args, env) == -1)
			{
				i++;
				free(cmd_path);
				ret(NULL, 127, 2);
			}
		}
		free (cmd_path);
	}
	i = return1(i);
	return (i);
}

int	if_path_not_exist(t_pars *pars, char **path_tab, char **env)
{
	int	i;

	(void)path_tab;
	i = 0;
	if (execve(pars->cmd, &pars->args[i], env) == -1)
			i++;
	if (i == 0)
	{
		return (-1);
	}
	return (0);
}

int	return1(int i)
{
	if (i == 0)
		return (-1);
	return (0);
}
