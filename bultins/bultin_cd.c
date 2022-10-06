#include "../minishell.h"

int	bultin_cd(t_pars *pars, t_node *env)
{
	char	*path;
	char	*tmp;

	if (pars->args[1] == NULL)
	{
		path = search_env(env, "HOME");
		if (path == NULL)
			return (0);
	}
	else
		path = pars->args[1];
	if (chdir(path) == -1)
	{
		tmp = ft_strjoin("cd: no such file or directory: ", path);
		ft_putstr_fd(tmp, 2);
		free(tmp);
		return (1);
	}
	return (0);
}
