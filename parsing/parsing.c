
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
				if (is_double_pipe(data, i) != -1 || check_pipe(data) != -1 || is_space_pipe(data, i) != -1)
				{
					return (-1);
				}
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

	i = -1;
	while (data[++i])
	{
		if (is_quote(data, i) == -1)
		{
			//printf("normalement le retour du i = -1 mais i = %d\n", i);
			return (-1);
		}
		else
			i = is_quote(data, i);
		//return (-1);
		//printf("la pute si i passe par la ... i = %d\n", i);
		//printf("i dans check = %d\n", i);
		//printf("bloque la data[%c], i = [%d]\n", data[i], i);
		if (data[i] == '|')
		{
			if (is_double_pipe(data, i) != -1 || check_pipe(data) != -1 || is_space_pipe(data, i) != -1)
			{
				return (-1);
			}
		}
		//return (0);
	}
	return (0);
}

void	is_zero(t_pars **pars, char *data, int i, int j)
{
	char	*tmp;

	tmp = ft_substr(data, j, i - j + 1);
	*pars = p_add_list(*pars, tmp);
}
