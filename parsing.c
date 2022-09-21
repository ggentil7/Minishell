
#include "minishell.h"

void	data_to_lst(t_pars **pars, char *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	tmp = NULL;
	while (data[++i])
	{
		if (data[i] == '|')
		{
			tmp = ft_substr(data, j, i - j);
			*pars = p_add_list(*pars, tmp);
			if (data[i + 1] == ' ')
			{
				while (data[i + 1] == ' ')
					i++;
			}
				j = i + 1;
		}
		if (data[i + 1] == '\0')
		{
			tmp = ft_substr(data, j, i - j + 1);
			*pars = p_add_list(*pars, tmp);
		}
	}
}
