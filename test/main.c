
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int	check_s_c(char *line);
int	check_d_c(char *line);

int	main(void)
{
	char	*line;

	while (42)
	{
		line = readline("test de merde : ");
		printf("single return (%d)\n", check_s_c(line));
		printf("double return (%d)\n", check_d_c(line));
	}
	free (line);
	return (0);
}

int	check_s_c(char *line)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (line[i])
	{
		if (line[i] == 39)
			compt++;
		i++;
	}
	if (compt % 2 == 1)
		return (1);
	return (0);
}

int	check_d_c(char *line)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (line[i])
	{
		if (line[i] == 34)
			compt++;
		i++;
	}
	if (compt % 2 == 1)
		return (1);
	return (0);
}
