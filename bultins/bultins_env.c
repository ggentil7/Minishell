/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:39:55 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:26:59 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bultin_env(t_pars *pars, t_node *env)
{
	t_node	*tmp;

	tmp = env;
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
	int	i;

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
	t_node	*env;
	char	**tab;
	int		i;

	i = 0;
	env = node;
	if (pars->args[1] == NULL)
	{
		tab = env_to_tab(env);
		tab = env_sort(tab);
		print_export(tab);
	}
	else
	{
		bultin_export_la_suite(pars, node);
	}
	return (0);
}

int	bultin_export_la_suite(t_pars *pars, t_node *node)
{
	t_node	*env;
	char	*tmp;
	int		i;

	i = 0;
	env = node;
	while (pars->args[++i])
	{
		tmp = check_equal_env(pars->args[i]);
		if (search_env_var(node, tmp) != NULL )
		{
			if (ft_strchr(pars->args[i], '=') != NULL)
			{
				del_env(node, tmp);
				add_to_export_lst(pars, env, pars->args[i]);
			}
		}
		else
			add_to_export_lst(pars, env, pars->args[i]);
		free (tmp);
	}
	return (0);
}
