#include "../minishell.h"

int	pipeline(t_pars *pars, t_node *env)
{
	t_pars	*tmp;
	
	tmp = pars;
	while (tmp != NULL)
	{
		tmp->pid = fork();
		if (tmp->pid == 0)
		{
			if (tmp->fd_out > 2)
				dup2(tmp->fd_out, STDOUT_FILENO);
			if (tmp->fd_in > 2)
				dup2(tmp->fd_in, STDIN_FILENO);
			free_pipe(pars);
			execution(tmp, env);
			exit (0);
		}
		tmp = tmp->next;
	}
	free_pipe(pars);
	tmp = pars;
	while (tmp != NULL)
	{
		if (tmp->pid > 0)
			waitpid(tmp->pid, NULL, 0);
		tmp = tmp->next;
	}
	return (0);
}

void	free_pipe(t_pars *pars)
{
	while (pars != NULL)
	{
		if (pars->fd_in > 2)
			close(pars->fd_in);
		if (pars->fd_out > 2)
			close(pars->fd_out);
		pars = pars->next;
	}
}