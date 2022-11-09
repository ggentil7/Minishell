/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chaine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:26:15 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:26:16 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

	cell = ft_calloc(sizeof(t_node), 1);
	if (!cell)
		return (0);
	cell->data = data;
	cell->args = NULL;
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
