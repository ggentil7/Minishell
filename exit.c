
#include "minishell.h"

int	exit_minishell(t_pars *pars, t_node *env, t_prompt *prompt)
{
	int	i;

	i = 0;
	if (pars->args[1] != NULL)
	{
		i = ft_atoi(pars->args[1]);
		ret("exit", 0, 0);
		free_prompt(pars, prompt);
		free_lst_node(env);
		exit (i);
	}
	else
	{
		ret("exit", 0, 0);
		free_prompt(pars, prompt);
		free_lst_node(env);
		exit (g_ret);
	}
	return (0);
}
