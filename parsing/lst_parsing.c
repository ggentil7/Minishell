#include "../minishell.h"

t_pars	*p_empty_lst(void)
{
	return (0);
}

int	p_isempty(t_pars *L)
{
	return (L == NULL);
}

t_pars	*p_create_cell(char *data)
{
	t_pars	*cell;

	cell = malloc(sizeof(t_pars));
	if (!cell)
		return (0);
	cell->p_data = data;
	cell->next = NULL;
	return (cell);
}

t_pars	*p_add_list(t_pars *L, char *data)
{
	t_pars	*cur;
	t_pars	*cell;

	cur = L;
	cell = p_create_cell(data);
	if (p_isempty(L))
		return (cell);
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = cell;
	return (L);
}

char	*p_getat(t_pars *L, int pos)
{
	int	i;

	i = 0;
	if (p_isempty(L))
	{
		printf("liste vide\n");
		return (NULL);
	}
	while (i < pos)
	{
		i++;
		L = L->next;
		if (L == NULL)
			return (NULL);
	}
	return (L->p_data);
}

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
		printf("clear\n");
	}
}

void	p_lstdelone(t_pars *lst)
{
	free(lst->p_data);
	free(lst);
}
