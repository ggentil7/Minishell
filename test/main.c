
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int	check_s_c(char *line);
int	check_d_c(char *line);
int	check_c(const char *str, int i);
int	remove_quote(char *data);

int	main(int ac, char **av)
{
	(void)ac;
	remove_quote(av);
	return (0);
}

int	remove_quote(char *data)
{
	int	i;
	int	j;
	int	k;
	int	*quote;
	//char	*new;

	j = 0;
	i = -1;
	k = 0;
	while (data[++i])
	{
		if (data[i] == '\'' || data[i] == '\"')
		{
			j = i;
			quote[k] = j;
			k++;
			i = is_quote(data, i);
			quote[k] = i;
			k++;
		}
	}
	return (0);
}