#include "../minishell.h"

int	check_pipe(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[0] == '|')
		{
			printf("Error parsing '|' !\n");
			return (-1);
		}
		//printf("avant data[%c], i = %d\n", data[i], i);
		i = is_quote(data, i);
		//printf("apres data[%c], i = %d\n", data[i], i);
		if (data[i] == '|')
		{
			if (is_double_pipe(data, i) == -1 || is_space_pipe(data, i) == -1 || is_bs_pipe(data, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	is_pipe(t_pars **pars, char *data, int i, int j)
{
	char	*tmp;
	int		y;

	y = 0;
	tmp = ft_substr(data, j, i - j);
	*pars = p_add_list(*pars, tmp);
}

int	is_double_pipe(char *data, int i)
{
	if (data[i + 1] == '|')
	{
		printf("Error parsing '|' !\n");
		return (-1);
	}
	return (0);
}

int	is_bs_pipe(char *data, int i)
{
	if (data[i + 1] == '\0')
	{
		printf("Error parsing '|' !\n");
		return (-1);
	}
	return (0);
}

int	is_space_pipe(char *data, int i)
{
	if (data[i + 1] == ' ')
	{
		i++;
		while (data[i] == ' ')
		{
			if (data[i + 1] == '|' || data[i + 1] == '\0')
			{
				printf("syntax error near unexpected token `|'\n");
				return (-1);
			}
			i++;
		}
	}
	return (0);
}
