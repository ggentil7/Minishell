
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_pars	*pars;
	
	(void)argc;
	(void)argv;
	node = NULL;
	pars = NULL;
	env_cpy(&node, envp);
	while (1)
	{
		signal(SIGINT, &handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		prompt(node, pars);
	}
	// lstclear(node);
	// rl_clear_history();
	return (0);
}
 