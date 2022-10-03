#include "../minishell.h"

int	lst_to_tab(t_pars *pars)
{
	// int		i;
	char **temp;

	// i = 0;
	temp = NULL;
	while (pars)
	{
		temp = ft_split_pipe(pars->p_data, ' ');
		//i = 0;
		pars->args = temp;
		pars = pars->next;
	}
	// i = -1;
	// while (temp[++i])
	// 	free (temp[i]);
	// free (temp);
	return (0);
}

