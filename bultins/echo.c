#include "../minishell.h"

int	bultin_echo(t_pars *pars)
{
	int	i;

	i = 1;
	while (pars->args[i])
	{
		ft_putstr_fd(pars->args[i], 1);
		if (pars->args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

/*int	flag_echo(t_pars *pars)
{
	int	i;

	i = 1;
	if (pars->args[i] == '-')
		return (1);
	while (pars->args[i])
	{
			if (pars->args[i] == 'n')
				return (1);
		i++;
	}
	return (0);
}*/

/*int	bultin_echo_n(t_pars *pars)
{
	int	i;

	i = 1;
	while (pars->args[i])
	{
		if (pars->args[i][0] == '-')
		{
			if (pars->args[i][1] == 'n')
				i++;
			else
				return (0);
		}
		ft_putstr_fd(pars->args[i], 1);
		if (pars->args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}*/

int	bultin_echo_n(t_pars *pars)
{
	int	i;

	i = 1;
	if (ft_strcmp(pars->args[1], "-n") == 0)
	{
		i = 2;
		while (pars->args[i])
		{
			// if (pars->args[i][0] == '-')
			// {
			// 	if (pars->args[i][1] == 'n')
			// 		i++;
			// 	else
			// 		return (0);
			// }
			ft_putstr_fd(pars->args[i], 1);
			if (pars->args[i + 1])
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else
		bultin_echo(pars);
	return (0);
}

int	bultin_cd(t_pars *pars, t_node *env)
{
	char	*path;
	char	*tmp;

	if (pars->args[1] == NULL)
	{
		path = search_env(env, "HOME");
		if (path == NULL)
			return (0);
	}
	else
		path = pars->args[1];
	if (chdir(path) == -1)
	{
		tmp = ft_strjoin("cd: no such file or directory: ", path);
		ft_putstr_fd(tmp, 2);
		//free(tmp);
		return (1);
	}
	return (0);
}

int	bultin_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	write(1, "\n", 1);
	//free(path);
	return (0);
}
