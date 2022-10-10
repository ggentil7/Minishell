#include "minishell.h"

int	init_cmd(t_pars *pars)
{
	if (pars->args != NULL)
		pars->cmd = pars->args[0];
	return (0);
}
