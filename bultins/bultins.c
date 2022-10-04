/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:12:24 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/04 17:13:07 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

int	bultin_search(t_pars *pars, t_node *env)
{
	if (ft_strcmp(pars->cmd, "echo") == 0)
	// 	return (bultin_echo(pars));
	// else if (ft_strcmp(pars->cmd, "cd") == 0)
	// 	return (bultin_cd(pars, env));
	// else if (ft_strcmp(pars->cmd, "pwd") == 0)
	// 	return (bultin_pwd(pars));
	// else if (ft_strcmp(pars->cmd, "export") == 0)
	// 	return (bultin_export(pars, env));
	// else if (ft_strcmp(pars->cmd, "unset") == 0)
	// 	return (bultin_unset(pars, env));
	// else if (ft_strcmp(pars->cmd, "env") == 0)
	// 	return (bultin_env(pars, env));
	// else if (ft_strcmp(pars->cmd, "exit") == 0)
	// 	return (bultin_exit(pars));
}

int	cmd(t_pars *pars, t_node *env)
{
	init_cmd(pars);
	bultin_search(pars, env);
}
