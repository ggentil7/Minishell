
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int	check_s_c(char *line);
int	check_d_c(char *line);
int	check_c(const char *str, int i);

int	main(void)
{
	char	*line;
	char	*tmp = "salut gab comment tu vas?";
	 int		i;
	 int		y;

	 i = -1;
	 y = 0;
	 while (tmp[++i] != ' ')
	 {
		if (tmp[i + 1] == ' ')
		{
			line = ft_substr(tmp, y, i + 1);
			printf("line 1 = %s\n", line);
		}
	 }
	 i++;
	 y = i;
	while (tmp[++i] != ' ')
	 {
		if (tmp[i + 1] == ' ')
		{
			line = ft_substr(tmp, y, i - y + 1);
			printf("line 2 = %s\n", line);
		}
	 }
	  i++;
	 y = i;
	while (tmp[++i] != ' ')
	 {
		if (tmp[i + 1] == ' ')
		{
			line = ft_substr(tmp, y, i - y + 1);
			printf("line 3 = %s\n", line);
		}
	 }
	  i++;
	 y = i;
	while (tmp[++i] != ' ')
	 {
		if (tmp[i + 1] == ' ')
		{
			line = ft_substr(tmp, y, i - y + 1);
			printf("line 4 = %s\n", line);
		}
	 }
	// while (666)
	// {
	// 	line = readline("test de merde de l'enfer : ");

	// }
	return (0);
}

// int	check_c(const char *str, int y)
// {
// 	int	i;

// 	i = 0;
// 	while (str[y++])
// 	{
// 		if (str[y] == '\"')
// 		{
// 			while (str[++y])
// 			{
// 				printf("y in = %d\n", y);
// 				if (str[y + 1] == '\"')
// 				{
// 					i = y;
// 					return (i);
// 				}
// 			}
// 		}
// 		printf("y = %d\n", y);
// 	}
// 	return (i);
// }

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
