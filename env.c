
#include "minishell.h"

void	env_cpy(t_node **node, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		*node = add_list(*node, envp[i]);
		i++;
	}
}
