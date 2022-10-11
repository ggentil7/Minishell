/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:12 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/10 17:51:21 by aboymond         ###   ########.fr       */
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
	t_node	*tmp;
	t_pars	*tmpars;
	int 	i;

	tmp = env;
	tmpars = pars;
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

int	bultin_export(t_pars *pars, t_node *node, t_args *args)
{
	t_pars	*pars_tmp;
	t_node	*node_tmp;
	char	**env;
	// char	**env2;
	(void)args;
	pars_tmp = pars;
	node_tmp = node;
	if (pars->args[1] == NULL)
	{
		env = env_to_tab(node);
		env = env_sort(env);
		print_export(env);
	}
	else
		add_to_export_lst(pars, node);

	//add_to_export_lst(pars, node);
	//add_to_export_tab(pars, args);
	//env2 = add_to_export_tab(pars);
	//args->args_tab = NULL;

	return (0);
}