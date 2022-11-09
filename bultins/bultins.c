/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:27:50 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:27:52 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bultin_search(t_pars *pars, t_node *env, t_prompt *prompt)
{
	if (ft_strcmp(pars->cmd, "echo") == 0 || ft_strcmp(pars->cmd, "ECHO") == 0)
		return (bultin_echo_n(pars, env));
	else if (ft_strcmp(pars->cmd, "cd") == 0)
		return (bultin_cd(pars, env));
	else if (ft_strcmp(pars->cmd, "pwd") == 0
		|| ft_strcmp(pars->cmd, "PWD") == 0)
		return (bultin_pwd(pars));
	if (ft_strcmp(pars->cmd, "export") == 0)
		return (bultin_export(pars, env));
	else if (ft_strcmp(pars->cmd, "EXPORT") == 0)
		return (ret(pars->cmd, 127, 1));
	if (ft_strcmp(pars->cmd, "unset") == 0)
		return (bultin_unset(pars, env));
	else if (ft_strcmp(pars->cmd, "UNSET") == 0)
		return (ret(pars->cmd, 127, 1));
	else if (ft_strcmp(pars->cmd, "env") == 0
		|| ft_strcmp(pars->cmd, "ENV") == 0)
		return (bultin_env(pars, env));
	else if (ft_strcmp(pars->cmd, "exit") == 0)
		return (exit_minishell(pars, env, prompt));
	return (-1);
}

int	cmd(t_pars *pars, t_node *env, t_prompt *prompt)
{
	signal(SIGINT, handle_sigquit);
	signal(SIGQUIT, handle_sigquit);
	redirection_tab(pars);
	init_cmd(pars);
	if (is_bultin(pars) != -1 && pars->next == NULL && pars->chevr == 0)
		bultin_search(pars, env, prompt);
	else
		pipeline(pars, env, prompt);
	return (0);
}

void	execution(t_pars *pars, t_node *env)
{
	char	**tmp;
	char	**tmp_env;

	tmp_env = env_to_tab(env);
	tmp = conv_path(pars, env);
	if_path_not_exist(pars, tmp, tmp_env);
	if (tmp == NULL || exec_bultout_2(pars, tmp, tmp_env) == -1)
	{
		ret(pars->cmd, 127, 1);
		free_lst_pars(pars);
		free_lst_node(env);
	}
	if (tmp != NULL)
		free_tab(tmp);
	if (tmp_env != NULL)
		free(tmp_env);
}

int	is_bultin(t_pars *pars)
{
	if (ft_strcmp(pars->cmd, "echo") == 0 || ft_strcmp(pars->cmd, "ECHO") == 0)
		return (0);
	else if (ft_strcmp(pars->cmd, "cd") == 0)
		return (0);
	else if (ft_strcmp(pars->cmd, "pwd") == 0
		|| ft_strcmp(pars->cmd, "PWD") == 0)
		return (0);
	if (ft_strcmp(pars->cmd, "export") == 0)
		return (0);
	else if (ft_strcmp(pars->cmd, "EXPORT") == 0)
		return (0);
	if (ft_strcmp(pars->cmd, "unset") == 0)
		return (0);
	else if (ft_strcmp(pars->cmd, "UNSET") == 0)
		return (0);
	else if (ft_strcmp(pars->cmd, "env") == 0
		|| ft_strcmp(pars->cmd, "ENV") == 0)
		return (0);
	else if (ft_strcmp(pars->cmd, "exit") == 0)
		return (0);
	return (-1);
}
