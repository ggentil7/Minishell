#include "../minishell.h"

int	chevron_d_simple(t_pars *pars, int i)
{
	int	fd;

	fd = open(pars->args[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error FD\n");
		return (0);
	}
	pars->fd_out = fd;
	del_chevron_more(pars, i);
	return (0);
}

int	chevron_d_double(t_pars *pars, int i)
{
	int fd;

	fd = open(pars->args[i], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		printf("Error FD\n");
		return (0);
	}
	pars->fd_out = fd;
	del_chevron_more(pars, i);
	return (0);
}

int	chevron_g_simple(t_pars *pars, int i)
{
	int fd;

	fd = open(pars->args[i], O_RDONLY);
	if (fd == -1)
	{
		printf("Error FD\n");
		return (0);
	}
	pars->fd_in = fd;
	del_chevron_more(pars, i);
	return (0);
}