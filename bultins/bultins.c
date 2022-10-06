
#include "../minishell.h"

int	bultin_search(t_pars *pars, t_node *env)
{
	if (ft_strcmp(*pars->args, "echo") == 0)
		return (bultin_echo_n(pars));
	else if (ft_strcmp(*pars->args, "cd") == 0)
		return (bultin_cd(pars, env));
	else if (ft_strcmp(*pars->args, "pwd") == 0)
		return (bultin_pwd(pars));
	// else if (ft_strcmp(pars->cmd, "export") == 0)
	// 	return (bultin_export(pars, env));
	// else if (ft_strcmp(pars->cmd, "unset") == 0)
	// 	return (bultin_unset(pars, env));
	// else if (ft_strcmp(pars->cmd, "env") == 0)
	// 	return (bultin_env(pars, env));
	// else if (ft_strcmp(pars->cmd, "exit") == 0)
	// 	return (bultin_exit(pars));
	return (0);
}

int	cmd(t_pars *pars, t_node *env)
{
	//init_cmd(pars);
	bultin_search(pars, env);
	return (0);
}
