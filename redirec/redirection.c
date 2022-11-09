/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:24:18 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:24:21 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirection_tab(t_pars *pars)
{
	t_pars	*tmp;
	int		i;

	tmp = pars;
	while (tmp != NULL)
	{
		tmp->chevr = 0;
		i = 0;
		while (tmp->args[i])
		{
			if (chevron_detect(tmp, tmp->args[i], i) == -1)
				i++;
			else
				tmp->chevr++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	chevron_detect(t_pars *pars, char *tab, int i)
{
	if (ft_strcmp(tab, ">") == 0)
	{
		del_chevron_more(pars, i);
		chevron_d_simple(pars, i);
	}
	else if (ft_strcmp(tab, "<") == 0)
	{
		del_chevron_more(pars, i);
		chevron_g_simple(pars, i);
	}
	else if (ft_strcmp(tab, ">>") == 0)
	{
		del_chevron_more(pars, i);
		chevron_d_double(pars, i);
	}
	else if (ft_strcmp(tab, "<<") == 0)
	{
		del_chevron_more(pars, i);
		chevron_g_double(pars, i);
	}
	else
		return (-1);
	return (0);
}

int	del_chevron_more(t_pars *pars, int i)
{
	int	j;

	free(pars->args[i]);
	j = i + 1;
	while (pars->args[j])
	{
		pars->args[i] = pars->args[j];
		i++;
		j++;
	}
	pars->args[i] = NULL;
	return (0);
}
