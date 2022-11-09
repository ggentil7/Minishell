/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:23:55 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:23:58 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	chevron_d_simple(t_pars *pars, int i)
{
	int	fd;

	fd = open(pars->args[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
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
	int	fd;

	fd = open(pars->args[i], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
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
	int	fd;

	fd = open(pars->args[i], O_RDONLY);
	if (fd == -1)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
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

	if (pars->args[i] == NULL)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (0);
	}
	error_pipe(fd);
	key = pars->args[i];
	line = NULL;
	fd[1] = while_chevron(line, key, fd);
	free (line);
	close (fd[1]);
	if (pars->fd_in > 2)
		close (pars->fd_in);
	pars->fd_in = fd[0];
	del_chevron_more(pars, i);
	return (0);
}

int	error_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (0);
	}
	return (0);
}
