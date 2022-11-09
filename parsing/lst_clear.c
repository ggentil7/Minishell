/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:20:37 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:21:12 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		i;

	i = 0;
	supp = node;
	if (node == NULL)
		return (NULL);
	i = (int)ft_strlen(data);
	while (supp != NULL)
	{
		if (ft_strncmp(supp->data, data, i) == 0
			&& (supp->data[i] == '=' || supp->data[i] == '\0'))
		{
			supp = lstclear_cell2(supp, node, prec, data);
		}
		else
		{
			prec = supp;
			supp = supp->next;
		}
	}
	return (node);
}
