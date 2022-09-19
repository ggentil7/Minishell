
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int	check_s_c(char *line);
int	check_d_c(char *line);
int	check_c(char *str);

int	main(void)
{
	char	*line;

	while (42)
	{
		line = readline("test de merde : ");
		check_c(line);
		//printf("single return (%d)\n", check_s_c(line));
		//printf("double return (%d)\n", check_d_c(line));
	}
	free (line);
	return (0);
}

int	check_c(char *str)
{
	int		i;
	// int		j;
	// int 	compt_i;
	// int		compt_j;
	int		compt;

	i = 0;
	// j = 0;
	// compt_i = 0;
	// compt_j = 0;
	compt = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			compt++;
			printf("compt = %d\n", compt);
			while (str[i] != 34 || !str[i])
			{
				i++;
			}
		}
	}
	// if (compt % 2 == 1)
	// 	return (1);
	return (0);
}

// int	check_s_c(char *line)
// {
// 	int	i;
// 	int	compt;

// 	i = 0;
// 	compt = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == 39)
// 			compt++;
// 		i++;
// 	}
// 	if (compt % 2 == 1)
// 		return (1);
// 	return (0);
// }

// int	check_d_c(char *line)
// {
// 	int	i;
// 	int	compt;

// 	i = 0;
// 	compt = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == 34)
// 			compt++;
// 		i++;
// 	}
// 	if (compt % 2 == 1)
// 		return (1);
// 	return (0);
// }
