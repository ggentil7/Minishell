#include "../minishell.h"

int	bultin_pwd(t_pars *pars)
{
	char	*path;
	(void)pars;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	write(1, "\n", 1);
	//free(path);
	return (0);
}

