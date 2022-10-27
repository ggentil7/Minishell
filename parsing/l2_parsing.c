
#include "../minishell.h"

int	lst_to_tab(t_pars *pars)
{
	char	**temp;

	temp = NULL;
	while (pars)
	{
		temp = ft_split_pipe(pars->p_data, ' ', pars);
		pars->args = temp;
		pars = pars->next;
	}
	return (0);
}
