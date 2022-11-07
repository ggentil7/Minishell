
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
	int		i;
	int		y;
	char	*cmd_path;
	char	*start_cmd_path;

	y = 0;
	i = 0;
	while (path_tab[y])
	{
		start_cmd_path = ft_strjoin(path_tab[y], "/");
		cmd_path = ft_strjoin(start_cmd_path, pars->cmd);
		free (start_cmd_path);
		if (!access(cmd_path, X_OK))
			if (execve(cmd_path, pars->args, env) == -1)
			{
				i++;
				free(cmd_path);
				printf("execve\n");
				ret(NULL, 127, 2);
			}
		free (cmd_path);
		y++;
	}
	if (i == 0)
	{
		return (-1);
	}
	return (0);
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
