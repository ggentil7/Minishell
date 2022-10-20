
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_pars	*pars;
	struct termios	saved;
	
	(void)argc;
	(void)argv;
	node = NULL;
	pars = NULL;
	env_cpy(&node, envp);
	while (1)
	{
		handle_signal(&saved);
		prompt(node, pars); // copie de la liste 
		tcsetattr(STDIN_FILENO, TCSANOW, &saved);
	}
	// lstclear(node);
	// rl_clear_history();
	return (0);
}
 