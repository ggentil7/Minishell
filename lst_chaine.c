/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chaine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:59:58 by piow00            #+#    #+#             */
/*   Updated: 2022/09/13 15:59:29 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

list	*empty_lst(void)
{
	return (0);
}

int	isempty(list *L)
{
	return (L == NULL);
}

cell	*create_cell(int data)
{
	cell	*cell;

	cell = malloc(sizeof(cell));
	if (!cell)
		return (0);
	cell->data = data;
	cell->data = 0;
	return (cell);
}

list	*add_list(list *L, int data, int pos)
{
	list	*prec;
	list	*cur;
	int		i;
	cell	*cell;

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
