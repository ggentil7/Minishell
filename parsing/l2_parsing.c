/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l2_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:24:56 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:24:58 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lst_to_tab(t_pars *pars, t_node *env)
{
	char	**temp;
	t_pars	*tmp;

	temp = NULL;
	tmp = pars;
	while (tmp)
	{
		temp = ft_split_pipe(tmp->p_data, ' ', tmp, env);
		tmp->args = temp;
		tmp = tmp->next;
	}
	return (0);
}
