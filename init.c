#include "minishell.h"

int	init_cmd(t_pars *pars)
{
	if (pars->args == NULL)
		return (0);
	pars->cmd = pars->args[0];
	return (0);
}

