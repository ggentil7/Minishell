# include "../minishell.h"



int	redirection_tab(t_pars *pars)
{
	t_pars *tmp;
	int	i;

	tmp = pars;
	i = 0;
	while (tmp != NULL)
	{
		while (tmp->args[i])
		{
			printf("tmp->args[%d] = %s\n", i, tmp->args[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

// int	redo_tab(t_pars *pars, int i, int j)
// {

// 	return (0);
// }
