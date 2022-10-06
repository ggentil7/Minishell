#include "minishell.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_pars	pars;

	pars.args = argv;
	echo_n(&pars);
	return (0);
}
