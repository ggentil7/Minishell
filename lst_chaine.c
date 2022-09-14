/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chaine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:59:58 by piow00            #+#    #+#             */
/*   Updated: 2022/09/14 16:34:42 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
