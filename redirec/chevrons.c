#include "../minishell.h"

int	chevron_d_simple(t_pars *pars, int i)
{
	int	fd;

	fd = open(pars->args[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error FD >\n");
		return (0);
	}
	if (pars->fd_out > 2)
		close(pars->fd_out);
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
		printf("Error FD >>\n");
		return (0);
	}
	if (pars->fd_out > 2)
		close(pars->fd_out);
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
		printf("Error FD <\n");
		return (0);
	}
	if (pars->fd_in > 2)
		close(pars->fd_in);
	pars->fd_in = fd;
	del_chevron_more(pars, i);
	return (0);
}

int	chevron_g_double(t_pars *pars, int i)
{
	int		fd[2];
	char	*line;
	char	*key;

	if (pipe(fd) == -1)
	{
		printf("Error pipe\n");
		return (0);
	}
	key = pars->args[i];
	line = NULL;
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			break ;
		if (ft_strcmp(line, key) != 0)
			ft_putendl_fd(line, fd[1]);
		else
			break ;
		free(line);
	}
	free (line);
	close (fd[1]);
	if (pars->fd_in > 2)
		close (pars->fd_in);
	pars->fd_in = fd[0];
	del_chevron_more(pars, i);
	return (0);
}