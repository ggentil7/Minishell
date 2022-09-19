
#include "minishell.h"

void	tk_data(t_pars **pars, char *data)
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
			//printf("tmp 1 = %s\n", tmp);
			*pars = p_add_list(*pars, tmp);
			j = i + 1;
		}
		if (data[i + 1] == '\0')
		{
			tmp = ft_substr(data, j, i - j + 1);
			//printf("tmp 2 = %s\n", tmp);
			*pars = p_add_list(*pars, tmp);
		}
	}
}
