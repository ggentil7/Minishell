#include "../minishell.h"

int	lst_to_tab(t_pars *pars)
{
	int		i;
	t_pars	*tmp;

	i = 0;
	tmp = pars;
	while (tmp)
	{
		// printf("cellule [%d]\t\n", i);
		tmp->args = ft_split_pipe(tmp->p_data, ' ');
		tmp = tmp->next;
		i++;
	}
	return (0);
}
