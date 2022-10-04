#include "../minishell.h"

void	p_lstclear(t_pars *lst)
{
	t_pars	*tmp;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		tmp = lst->next;
		p_lstdelone(lst);
		lst = tmp;
	}
}

void	p_lstdelone(t_pars *lst)
{
	free(lst->p_data);
	free(lst);
}

void	lstclear(t_node *lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		lstdelone(lst);
		lst = tmp;
	}
}

void	lstdelone(t_node *lst)
{
	free (lst->data);
	free (lst);
}
