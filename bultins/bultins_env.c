/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:12 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/26 17:04:54 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

int	bultin_env(t_pars *pars, t_node *env)
{
	t_node	*tmp;
	//t_pars	*tmpars;

	tmp = env;
	//tmpars = pars;
	if (pars->args[1] == NULL)
	{
		print_env(tmp);
	}
	else
	{
		printf("env: %s: No such file or directory\n", pars->args[1]);
		return (127);
	}
	return (0);
}

int	bultin_unset(t_pars *pars, t_node *env)
{
	int 	i;

	i = 1;
	if (pars->args[1] == NULL)
	{
		printf("unset: not enough arguments\n");
		return (1);
	}
	else
	{
		while (pars->args[i])
		{
			lstclear_cell(env, pars->args[i]);
			i++;
		}
	}
	return (0);
}

int	bultin_export(t_pars *pars, t_node *node)
{
	t_node	*tmp;

	tmp = node;
	// printf("export = %s\n", tmp->data);
	if (pars->args[1] == NULL)
	{
		tmp->args = env_to_tab(tmp);
		tmp->args = env_sort(tmp->args);
		print_export(tmp->args);
	}
	else
		add_to_export_lst(pars, tmp);

	return (0);
}