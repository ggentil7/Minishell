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
