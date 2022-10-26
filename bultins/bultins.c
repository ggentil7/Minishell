
#include "../minishell.h"

int	bultin_search(t_pars *pars, t_node *env)
{
	if (ft_strcmp(pars->cmd, "echo") == 0 || ft_strcmp(pars->cmd, "ECHO") == 0)
	 	return (bultin_echo_n(pars));
	 else if (ft_strcmp(pars->cmd, "cd") == 0)
	 	return (bultin_cd(pars, env));
	 else if (ft_strcmp(pars->cmd, "pwd") == 0
	 	|| ft_strcmp(pars->cmd, "PWD") == 0)
	 	return (bultin_pwd(pars));
	if (ft_strcmp(pars->cmd, "export") == 0)
		return (bultin_export(pars, env));
	else if (ft_strcmp(pars->cmd, "EXPORT") == 0)
		return (127);
	if (ft_strcmp(pars->cmd, "unset") == 0)
		return (bultin_unset(pars, env));
	else if (ft_strcmp(pars->cmd, "UNSET") == 0)
		return (127);
	else if (ft_strcmp(pars->cmd, "env") == 0
		|| ft_strcmp(pars->cmd, "ENV") == 0)
		return (bultin_env(pars, env));
	return (-1);
}

int	cmd(t_pars *pars, t_node *env)
{
	init_cmd(pars);
	redirection_tab(pars);
	if(is_bultin(pars) != -1 && pars->next == NULL && pars->chevr == 0)
		bultin_search(pars, env);
	else
		pipeline(pars, env);
	return (0);
}

void	execution(t_pars *pars, t_node *env)
{
	char	**tmp;

	tmp = conv_path(pars, env);
	if (exec_bultout_2(pars, tmp) == -1)
	{
		printf("minishell: %s: command not found\n", pars->cmd);
	}
	free_tab(tmp);
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
	return (-1);
}