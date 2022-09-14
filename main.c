
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	
	(void)argc;
	(void)argv;
	node = NULL;
	env_cpy(&node, envp);
	while (1)
		prompt(node); // copie de la liste 
	return (0);
}
 