/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:12 by aboymond          #+#    #+#             */
/*   Updated: 2022/11/07 13:33:52 by aboymond         ###   ########.fr       */
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
	char 	*tmp2;
	char 	*tmp3;
	int		i;
	i = 0;
	tmp = node;
	if (pars->args[1] == NULL)
	{
		tmp->args = env_to_tab(tmp);
		tmp->args = env_sort(tmp->args);
		print_export(tmp->args);
	}
	else
	{
		i = 0;
		while (pars->args[++i])
		{
			tmp2 = check_equal(pars->args[i]);
			if (search_env(tmp, tmp2) != NULL )
			{
				if(ft_strchr(pars->args[i], '=') != NULL)
				{
					tmp3 = del_env(tmp, tmp2);
					add_to_export_lst(pars, tmp, pars->args[i]);
				}
			}
			else
				add_to_export_lst(pars, tmp, pars->args[i]);
		}
	}
	return (0);
}

