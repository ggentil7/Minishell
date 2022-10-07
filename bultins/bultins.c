/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:12:24 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/06 23:29:15 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bultin_search(t_pars *pars, t_node *env, t_args *args)
{
	//if (ft_strcmp(pars->cmd, "echo") == 0)
	// 	return (bultin_echo(pars));
	// else if (ft_strcmp(pars->cmd, "cd") == 0)
	// 	return (bultin_cd(pars, env));
	// else if (ft_strcmp(pars->cmd, "pwd") == 0)
	// 	return (bultin_pwd(pars));
	if (ft_strcmp(pars->cmd, "export") == 0)
		return (bultin_export(pars, env, args));
	// else if (ft_strcmp(pars->cmd, "unset") == 0)
	// 	return (bultin_unset(pars, env));
	else if (ft_strcmp(pars->cmd, "env") == 0)
		return (bultin_env(pars, env));
	// else if (ft_strcmp(pars->cmd, "exit") == 0)
	// 	return (bultin_exit(pars));
	return (0);
}

int	cmd(t_pars *pars, t_node *env, t_args *args)
{
	init_cmd(pars);
	bultin_search(pars, env, args);
	return (0);
}
