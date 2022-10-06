/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:12 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/06 19:34:49 by aboymond         ###   ########.fr       */
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

int	bultin_export(t_pars *pars, t_node *node)
{
	t_args	*args;
	t_pars	*pars_tmp;
	t_node	*node_tmp;
	char	**env;
	char	**env2;

	pars_tmp = pars;
	node_tmp = node;
	args = malloc(sizeof(t_args) * 1);
	if (pars->args[1] == NULL)
	{
		env = env_to_tab(node_tmp);
		if (args->args != NULL)
		{
			env2 = tabjoin(env, args);
			//env = env_sort(env2);
		}
		else
			env2 = env_sort(env);
		print_export(env2);
		//free_tab(env2);
	}
	else
	{
		add_to_export(pars_tmp, node, args);
	}
	return (0);
}