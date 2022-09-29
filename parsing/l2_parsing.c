#include "../minishell.h"

int	lst_to_tab(t_pars *pars)
{
	int		i;
	t_pars	*tmp;

	i = 0;
	tmp = pars;
	while (tmp)
	{
		printf("tmp = %s\n", tmp->p_data);
		tmp->args = ft_split_pipe(tmp->p_data, ' ');
		tmp = tmp->next;
		i++;
	}
	return (0);
}
