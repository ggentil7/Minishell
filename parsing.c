
#include "minishell.h"

void	tk_data(t_pars **pars, char *data)
{
	int		i;
	int		j;
   // t_pars  *tmp;
	char	*temp;

	i = -1;
	j = 0;
   // tmp = pars;
	temp = NULL;
	while (data[i])
	{
		// printf("i = %d, j = %d\n", i, j);
		// if (i == ft_istrlen(data))
		// {
		// 	temp = ft_substr(data, j, i);
		// 	printf("temp data = %s\n", temp);
		// 	*pars = p_add_list(*pars, temp);
		// }
		if (data[i] == ' ' || data[i])
		{
			temp = ft_substr(data, j, i - j);
			printf("temp = %s\n", temp);
			*pars = p_add_list(*pars, temp);
			j = i;
		}
		temp = NULL;
	}
}