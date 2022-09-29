
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_pars	*pars;
	
	(void)argc;
	(void)argv;
	pars = NULL;
	node = NULL;
	env_cpy(&node, envp);
		// signal(SIGINT, &handle_sigint);
		// signal(SIGQUIT, SIG_IGN);
	while (1)
	{

		signal(SIGINT, &handle_sigint);
		signal(SIGQUIT, SIG_IGN);

		prompt(node, pars); // copie de la liste 
	}
	rl_clear_history();
	return (0);
}
 