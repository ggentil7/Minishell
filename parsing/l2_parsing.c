
#include "../minishell.h"

int	lst_to_tab(t_pars *pars)
{
	char	**temp;

	temp = NULL;
	while (pars)
	{
		temp = ft_split_pipe(pars->p_data, ' ');
		pars->args = temp;
		printf("pars = %s len = %d\n", pars->args[0], (int)strlen(pars->args[0]));
		pars = pars->next;
	}
	return (0);
}
