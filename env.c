
#include "minishell.h"

char	**env_cpy(char **envp)
{
	int		i;
	int		tmp;
	char	**env;

	i = 0;
	tmp = 0;
	while (envp[tmp])
	{
		tmp++;
	}
	env = malloc(sizeof(char *) * tmp + 1);
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		//printf("%s\n", env[i]);
		i++;
	}
	return (env);
}
