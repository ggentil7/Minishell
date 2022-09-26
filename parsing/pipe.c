#include "../minishell.h"

int	check_pipe(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		i = is_quote(data, i);
		if (data[i] != '|')
		{
			i++;
		}
		else
		{
			if (is_double_pipe(data, i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
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
		return (0);
	}
	return (1);
}

int	is_space_pipe(char *data, int i)
{
	if (data[i + 1] == ' ')
	{
		i++;
		while (data[i] == ' ')
		{
			if (data[i + 1] == '|')
			{
				printf("syntax error near unexpected token `|'\n");
				return (0);
			}
			i++;
		}
	}
	return (1);
}
