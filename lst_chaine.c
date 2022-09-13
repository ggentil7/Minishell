/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chaine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:59:58 by piow00            #+#    #+#             */
/*   Updated: 2022/09/13 17:08:56 by aboymond         ###   ########.fr       */
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

t_node	*create_cell(int data)
{
	t_node	*cell;

	cell = malloc(sizeof(cell));
	if (!cell)
		return (0);
	cell->data = data;
	cell->data = 0;
	return (cell);
}

t_node	*add_list(t_node *L, int data, int pos)
{
	t_node	*prec;
	t_node	*cur;
	int		i;
	t_node	*cell;

	prec = L;
	cur = L;
	i = 0;
	cell = create_cell(data);
	if (!isempty(L))
		return (cell);
	if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (L);
}
