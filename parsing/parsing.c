
#include "../minishell.h"

int	data_to_lst(t_pars **pars, char *data)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (check_data_to_lst(data) == -1)
		return (-1);
	else
	{
		while (data[++i])
		{
			i = is_quote(data, i);
			if (data[i] == '|')
			{
				is_pipe(pars, data, i, j);
				if (data[i + 1] == ' ')
					while (data[i + 1] == ' ')
						i++;
					j = i + 1;
			}
			if (data[i + 1] == '\0')
				is_zero(pars, data, i, j);
		}
	}
	return (0);
}

int	check_data_to_lst(char *data)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (data[i])
	{
		j = i;
		//printf("avant is_quote: data [%c], i = [%d]\n", data[i], i);
		i = is_quote(data, i);
		//printf("apres is_quote: data [%c], i = [%d]\n", data[i], i);
		if (j != i)
			i++;
		//printf("avant after_is_quote: data [%c], i = [%d]\n", data[i], i);
		if (after_is_quote(data, i) == -1)
		{
			//printf("dans after_is_quote: data [%c], i = [%d]\n", data[i], i);
			printf("Error parsing quotes !\n");
			return (-1);
		}
		//printf("apres after_is_quote: data [%c], i = [%d]\n", data[i], i);
		if (data[i] == '|')
		{
			if (is_double_pipe(data, i) == -1 || check_pipe(data) == -1 || is_space_pipe(data, i) == -1)
				return (-1);
		}
		if (data[i] == '\0')
			return (0);
		if (data[i] != '\'' && data[i] != '\"')
			i++;
	}
	return (0);
}

void	is_zero(t_pars **pars, char *data, int i, int j)
{
	char	*tmp;

	tmp = ft_substr(data, j, i - j + 1);
	*pars = p_add_list(*pars, tmp);
}
