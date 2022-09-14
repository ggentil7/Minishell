
#include "minishell.h"

void	env_cpy(/*t_envi *envi,*/ t_node **node, char **envp)
{
	int		i;
	char	*tmp = NULL;

	(void)node;
	i = 0;
	tmp = NULL;
	while (envp[i])
	{
		// printf("test\n");
		// conv_to_char(i, envp);
		*node = add_list(*node, envp[i]);
		//printf("%s\n", getat(node, i));
		i++;
	}
}
