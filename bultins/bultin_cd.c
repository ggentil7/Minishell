#include "../minishell.h"

int	bultin_cd(t_pars *pars, t_node *env)
{
	char	*path;

	if (pars->args[1] == NULL)
	{
		path = search_env(env, "");
		if (path == NULL)
			return (0);
	}
	else
		path = pars->args[1];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}
