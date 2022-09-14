/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chaine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:59:58 by piow00            #+#    #+#             */
/*   Updated: 2022/09/14 14:48:22 by aboymond         ###   ########.fr       */
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
	// cell->data = 0;
	return (cell);
}

t_node	*add_list(t_node *L, char *data/*, int pos*/)
{
	//t_node	*prec;
	t_node	*cur;
	// int		i;
	t_node	*cell;

	//prec = L;
	cur = L;
	// i = 0;
	cell = create_cell(data);
	if (isempty(L))
		return (cell);
	while (cur->next != NULL)
		cur = cur->next;
	// if (pos == 0)
	// {
	// 	cell->next = L;
	// 	return (cell);
	// }
	// while (i < pos)
	// {
	// 	i++;
	// 	prec = cur;
	// 	cur = cur->next;
	// }
	//prec->next = cell;
	cur->next = cell;
	//cell->next = cur;
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
