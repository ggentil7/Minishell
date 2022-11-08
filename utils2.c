#include "./minishell.h"

char	*check_equal(char *str)
{
	char	*tmp;
	char	*tmp2;
	int 	i;

	i = -1;
	tmp2 = ft_strdup(str);
	// printf("check equal tmp2 = [%p], str = [%p]\n", tmp2, str);
	while (str[++i])
		if (str[i] == '=')
		{
			tmp = ft_substr(str, 0, i);
			free (tmp2);
			// printf("\033[0;34mcheck equal tmp = [%s] [%p], str = [%s]  [%p]\033[0m\n",tmp, tmp, str, str);
			return (tmp);
		}
		return (tmp2);
}
char	*check_equal_env(char *str)
{
	char	*tmp;
	char	*tmp2;
	int 	i;

	i = -1;
	tmp2 = ft_strdup(str);
	// printf("check equal tmp2 = [%p], str = [%p]\n", tmp2, str);
	while (str[++i])
		if (str[i] == '=')
		{
			tmp = ft_substr(str, 0, i);
			free (tmp2);
			// printf("\033[0;34mcheck equal tmp = [%s] [%p], str = [%s]  [%p]\033[0m\n",tmp, tmp, str, str);
			return (tmp);
		}
		return (tmp2);
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

