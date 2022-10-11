#include "minishell.h"

int	init_cmd(t_pars *pars)
{
	if (pars->args != NULL)
		pars->cmd = pars->args[0];
	return (0);
}

void	init_all(t_pars *pars, t_node *env)
{
	(void)env;
	(void)pars;
}
