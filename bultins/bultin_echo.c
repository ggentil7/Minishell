#include "../minishell.h"

int	bultin_echo(t_pars *pars, int i, t_node *env)
{
	char	*tmp;
	char	*tmp_env;

	while (pars->args[i])
	{
		if (pars->doll_flag[i] == 1)
		{
			tmp = remove_dollars(pars->args[i]);
			tmp_env = search_env(env, tmp);
			if (tmp_env == NULL)
				return (-1);
			free (tmp);
			tmp = reste(tmp_env);
			ft_putstr_fd(tmp, 1);
			ft_putstr_fd(" ", 1);
			free(tmp);
		}
		else
		{
			ft_putstr_fd(pars->args[i], 1);
			if (pars->args[i + 1])
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
	return (0);
}

int	bultin_echo_n(t_pars *pars, t_node *env)
{
	int	i;

	i = 1;
	if (pars->args[1] == NULL)
		write(1, "\n", 1);
	else
	{
		if (ft_strcmp(pars->args[1], "-n") == 0)
		{
			i = 2;
			bultin_echo(pars, i, env);
		}
		else
		{
			bultin_echo(pars, i, env);
			write(1, "\n", 1);
		}
	}
	return (0);
}
