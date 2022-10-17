
#include "../minishell.h"

char	**conv_path(t_pars *pars, t_node *env)
{
	char	*path;
	char	**path_t;
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
	path_t = ft_split(path, ':');
	path_tab_tmp = path_t[0];
	path_t[0] = ft_substr(path_t[0], y + 1, (int)ft_strlen(path_t[0]) + 1);
	free (path_tab_tmp);
	return (path_t);
}

int	test_exec(t_pars *pars, t_node *env, char **path_tab)
{
	int		i;
	int		y;
	char	*cmd_path;
	char	*start_cmd_path;

	i = 0;
	y = 0;
	while (path_tab[y])
	{
		start_cmd_path = ft_strjoin(path_tab[y], "/");
		cmd_path = ft_strjoin(start_cmd_path, pars->cmd);
		free (start_cmd_path);
		if (!access(cmd_path, X_OK))
			if (execve(cmd_path, &pars->args[i], NULL) == -1)
				i++;
		free (cmd_path);
		y++;
	}
	if (i == 0)
	{
		free_tab(path_tab);
		return (-1);
	}
	free_tab(path_tab);
	return (0);
}
