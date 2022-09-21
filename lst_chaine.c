#include "minishell.h"

t_node	*empty_lst(void)
{
	return (0);
}

int	isempty(t_node *L)
{
	return (L == NULL);
}

t_node	*create_cell(char *data)
{
	t_node	*cell;

	cell = malloc(sizeof(cell));
	if (!cell)
		return (0);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

t_node	*add_list(t_node *L, char *data)
{
	t_node	*cur;
	t_node	*cell;

	cur = L;
	cell = create_cell(data);
	if (isempty(L))
		return (cell);
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = cell;
	return (L);
}

char	*getat(t_node *L, int pos)
{
	int	i;

	i = 0;
	if (isempty(L))
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
	return (L->data);
}

// void	ft_lstclear(t_node **lst, void (*del)(void *))
// {
// 	t_node	*tmp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = tmp;
// 	}
// }

// void	ft_lstdelone(t_node *lst, void (*del)(void *))
// {
// 	del(lst->content);
// 	free(lst);
// }
