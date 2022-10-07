/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:12 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/07 16:15:12 by aboymond         ###   ########.fr       */
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
		while (tmp)
		{
			printf("%s\n", tmp->data);
			tmp = tmp->next;
		}
	}
	else
	{
		printf("env: %s: No such file or directory\n", pars->args[1]);
		return (127);
	}
	return (0);
}

// int	bultin_unset(t_pars *pars, t_node *env)
// {
// 	t_node	*tmp;
// 	t_pars	*tmpars;

// 	tmp = env;
// 	tmpars = pars;
// 	if (pars->args[1] == NULL)
// 	{
// 		printf("unset: not enough arguments\n");
// 		return (1);
// 	}
// }

int	bultin_export(t_pars *pars, t_node *node, t_args *args)
{
	t_pars	*pars_tmp;
	t_node	*node_tmp;
	// char	**env;
	// char	**env2;

	pars_tmp = pars;
	node_tmp = node;
	//add_to_export_lst(pars, node);
	//add_to_export_tab(pars, args);
	//env2 = add_to_export_tab(pars);
	//args->args_tab = NULL;
	args->args_lst = env_to_tab(add_to_export_lst(pars, node));
	if (pars->args[1] == NULL)
	{
		
		if (args->args_tab != NULL)
		{
			args->args_tab = tabjoin(args->args_tab, args->args_lst);
			args->args_tab = env_sort(args->args_tab);
		}
		else 
			args->args_tab = args->args_lst;	
		print_export(args->args_tab);
	}
	else
	{
		args->args_tab = add_to_export_tab(pars, args);
		// env2 = tabjoin(add_to_export_tab(pars), env);
	}
	return (0);
}