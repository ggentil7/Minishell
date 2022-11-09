/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:23:35 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:23:38 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (tab != NULL)
	{
		j = ft_tablen(tab) + 1;
		while (i < j)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_lst_pars(t_pars *pars)
{
	t_pars	*tmp;

	tmp = pars;
	if (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
			while (tmp != NULL)
			{
				free_tab(tmp->args);
				tmp = tmp->next;
			}
			p_lstclear(pars);
		}
		else
		{
			free_tab(tmp->args);
			p_lstclear(pars);
		}
	}
	else
		return ;
}

void	free_prompt(t_pars *pars, t_prompt *prompt)
{
	free_lst_pars(pars);
	free(prompt->buffer);
	free(prompt->user);
}

void	free_lst_node(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			free_tab(tmp->args);
			tmp = tmp->next;
		}
	}
	else
		return ;
}
