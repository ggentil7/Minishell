
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_pars	*pars;
	t_prompt	*prompt;
	struct termios	saved;
	
	(void)argc;
	(void)argv;
	node = NULL;
	pars = NULL;
	prompt = ft_calloc(1, sizeof(t_prompt));
	env_cpy(&node, envp);
	while (1)
	{
		handle_signal(&saved);
		prompt_(node, pars, prompt); // copie de la liste 
		tcsetattr(STDIN_FILENO, TCSANOW, &saved);
	}
	// lstclear(node);
	// rl_clear_history();
	return (0);
}
 