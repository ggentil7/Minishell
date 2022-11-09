/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:24:35 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:24:36 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pipeline(t_pars *pars, t_node *env, t_prompt *prompt)
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
			if (bultin_search(tmp, env, prompt) == -1)
				execution(tmp, env);
			exit (127);
		}
		tmp = tmp->next;
	}
	free_pipe(pars);
	wait_pipe(pars);
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

void	wait_pipe(t_pars *pars)
{
	t_pars	*tmp;

	tmp = pars;
	while (tmp != NULL)
	{
		if (tmp->pid > 0)
		{
			waitpid(tmp->pid, &g_ret, 0);
			if (WIFSIGNALED(g_ret))
				g_ret = 128 + g_ret;
			if (WIFEXITED(g_ret))
				g_ret = WEXITSTATUS(g_ret);
		}
		tmp = tmp->next;
	}
}
