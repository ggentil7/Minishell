#include "../minishell.h"

int	print_export(char **env)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (env[++i])
	{
		printf("\033[1;31mdeclare -x \033[0m");
		j = 0;
		while (j < (int)ft_strlen(env[i]))
		{
			printf("\033[1;94m%c\033[0m", env[i][j]);
			if (env[i][j] == '=')
			{
				j++;
				printf("\033[1;92m\"");
				while (env[i][j] != '\0')
				{
					printf("%c", env[i][j]);
					j++;
				}
				printf("\"\033[0m");
			}
			j++;
		}
		printf("\n");
	}
	return (0);
}
