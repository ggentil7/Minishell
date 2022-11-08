#include "../minishell.h"

int	bultin_echo(t_pars *pars, int i, t_node *env)
{
	(void)env;
	while (pars->args[i])
	{
		if (ft_strcmp(pars->args[i], "$?") == 0)
			ft_putnbr_fd(g_ret, 1);
		else
			ft_putstr_fd(pars->args[i], 1);
		if (pars->args[i + 1])
			ft_putchar_fd(' ', 1);
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
