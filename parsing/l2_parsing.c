
#include "../minishell.h"

int	lst_to_tab(t_pars *pars)
{
	char	**temp;
	t_pars	*tmp;

	temp = NULL;
	tmp = pars;
	while (tmp)
	{
		temp = ft_split_pipe(tmp->p_data, ' ', tmp);
		tmp->args = temp;
		tmp = tmp->next;
	}
	return (0);
}
