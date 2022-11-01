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

t_node	*lstclear_cell(t_node *node, char *data)
{
	t_node	*supp;
	t_node	*prec;
	t_node	*tmp;
	int		i;

	i = 0;
	supp = node;
	if ( node == NULL)
		return (NULL);
	while (i < (int)ft_strlen(data))
	{
		i++;
	}
	while (supp != NULL)
	{
		if (ft_strncmp(supp->data, data, i) == 0 && (supp->data[i] == '=' || supp->data[i] == '\0'))
		{
			if (ft_strcmp(data, node->data))
			{
				tmp = supp->next->next;
				free(supp->data);
				supp->data = ft_strdup(supp->next->data);
				// supp = supp->next;
				free (supp->next->data);
				free (supp->next);
				supp->next = tmp;
			}
			else
			{
				prec->next = supp->next;
				tmp = supp->next;
				free(supp->data);
				free (supp);
				supp = tmp;
			}
		}
		else
		{
			prec = supp;
			supp = supp->next;
		}
	}
	return (node);
}