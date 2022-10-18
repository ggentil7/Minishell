#include "../minishell.h"

int	pipeline(t_pars *pars, t_node *env)
{
	
	pid_t	pid;
	int		status;
	int		i;

	i = 0;
	(void)env;
	

	//printf("FD IN = %d\n", fd[0]);
	while (pars != NULL)
	{
		//printf("TEEEEST pipeline\n");
		pid = fork();
		//printf("i = %d\n", i);
		if (pid == 0)
		{
			//printf("PID == 0\n");
				//printf("fd 1 = %d, i = %d\n", fd[1], i);
			if (pars->fd_in > 2 && pars->fd_out > 2)
			{
				fprintf(stderr, "fd_in = %d\n", pars->fd_in);
				dup2(pars->fd_in, 0);
				fprintf(stderr, "fd_out = %d\n", pars->fd_out);
				dup2(pars->fd_out, 1);
				close(pars->fd_in);
				close(pars->fd_out);
			}


			init_cmd(pars);
			execution(pars, env);
			exit (0);
		}
		waitpid(pid, &status, 0);
		//printf("pars pipeline %s\n", pars->p_data);
		pars = pars->next;
	}
	return (0);
}
