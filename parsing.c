
#include "minishell.h"

void	data_to_lst(t_pars **pars, char *data)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (data[++i])
	{
		i = is_quote(data, i);
		if (data[i] == '|')
		{
			is_pipe(pars, data, i, j);
			if (data[i + 1] == ' ')
			{
				while (data[i + 1] == ' ')
					i++;
			}
				j = i + 1;
		}
		if (data[i + 1] == '\0')
		{
			is_zero(pars, data, i, j);
		}
	}
}

void	is_pipe(t_pars **pars, char *data, int i, int j)
{
	char	*tmp;

	tmp = ft_substr(data, j, i - j);
	*pars = p_add_list(*pars, tmp);
}

void	is_zero(t_pars **pars, char *data, int i, int j)
{
	char	*tmp;

	tmp = ft_substr(data, j, i - j + 1);
	*pars = p_add_list(*pars, tmp);
}


