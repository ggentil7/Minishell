#include "minishell.h"

int	init_cmd(t_pars *pars)
{
	if (pars->args != NULL)
		pars->cmd = pars->args[0];
	//printf("cmd init = %s\n", pars->cmd);
	return (0);
}

void	init_pipe(t_pars *pars)
{
	int	fd[2];
	t_pars *tmp;
	int	i;

	i = 0;
	tmp = pars;
	tmp->fd_in = 0;
	while (tmp->next != NULL)
	{
		pipe(fd);
		tmp->fd_out = fd[1];
		tmp->next->fd_in = fd[0];
		tmp = tmp->next;
		i = 1;
	}
	tmp->fd_out = 1;
	tmp = pars;

	while(tmp)
	{
		printf("fd in = %d, fd out = %d\n", tmp->fd_in, tmp->fd_out);
		tmp = tmp->next;
	}
	// exit (0);
}
