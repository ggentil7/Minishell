
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_pars	*pars;
	t_args	*args;
	
	(void)argc;
	(void)argv;
	node = NULL;
	pars = NULL;
	args = ft_calloc(sizeof(t_args), 1);
	init_all(pars, node, args);
	env_cpy(&node, envp);
	while (1)
	{
		signal(SIGINT, &handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		prompt(node, pars); // copie de la liste 
	}
	lstclear(node);
	rl_clear_history();
	return (0);
}
 