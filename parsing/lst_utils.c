/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:08:11 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:17:59 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_node	*lstclear_cell2(t_node *supp, t_node *node, t_node *prec, char *data)
{
	t_node	*tmp;

	if (ft_strcmp(node->data, search_env(node, data)) == 0)
	{
		tmp = supp->next->next;
		free(supp->data);
		supp->data = ft_strdup(supp->next->data);
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
	return (supp);
}
