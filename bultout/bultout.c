#include "../minishell.h"

char	**conv_path(t_pars *pars, t_node *env)
{
	char	*path;
	char	**path_tab;
	char	*path_tab_tmp;
	int		i;
	int		y;

	(void)pars;
	i = 0;
	y = 0;
	path = search_env(env, "PATH");
	while (path[y] != '=')
	{
		if (path[y] == '\0')
			return (0);
		y++;
	}
	path_tab = ft_split(path, ':');
	path_tab_tmp = path_tab[0];
	path_tab[0] = ft_substr(path_tab[0], y + 1, (int)ft_strlen(path_tab[0]) + 1);
	free (path_tab_tmp);
	while (path_tab[i])
	{
		y = 0;
		printf("path_tab = %s  [%d]\n", path_tab[i], i);
		i++;
	}
	return (path_tab);
}

int	test_exec(t_pars *pars, t_node *env, char **path_tab)
{
	int	i;
	int	y;
	char	*cmd_path;
	char	*start_cmd_path;

	(void)env;
	i = 0;
	y = 0;
	while (path_tab[y])
	{
		start_cmd_path = ft_strjoin(path_tab[y], "/");
		cmd_path = ft_strjoin(start_cmd_path, pars->cmd);
		free (start_cmd_path);
		if (!access(cmd_path, X_OK))
		{
			if (execve(cmd_path, &pars->args[i], NULL) == -1)
			{
				i++;
			}
		}
		free (cmd_path);
		y++;
	}
	if (i == 0)
	{
		free_tab(path_tab);
		//free (cmd_path);
		return (-1);
	}
	free_tab(path_tab);
	// while (pars->args[i])
	// {
	// 	while (execve(pars->cmd, &pars->args[i], &path_tab[y]) == -1 && path_tab[y])
	// 	{
	// 		printf("cmd %s, args %s, path %s\n", pars->cmd, pars->args[i], path_tab[i]);
	// 		y++;
	// 	}
	// 	execve(pars->cmd, &pars->args[i], &path_tab[y]);
	// 	printf("execve = %d\n", execve(pars->cmd, &pars->args[i], path_tab));
	// 	i++;
	// }
	return (0);
}