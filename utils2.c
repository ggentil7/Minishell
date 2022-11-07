#include "./minishell.h"

char	*check_equal(char *str)
{
	char	*tmp;
	int i = -1;

	while (str[++i])
		if (str[i] == '=')
			return (tmp = ft_substr(str, 0, i));
	return (ft_substr(str, 0, i));
}

int	check_chev(char *chevr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (chevr[i])
	{
		if (chevr[i] == '>' || chevr[i] == '<')
			j++;
		i++;
	}
	if (i == j)
	{
		ret("syntax error near unexpected token `newline'", 258, 0);
		return (-1);
	}
	return (0);
}





