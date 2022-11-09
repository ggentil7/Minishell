/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:23:28 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:23:31 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_cmd(t_pars *pars)
{
	t_pars	*tmp;

	tmp = pars;
	if (tmp->args != NULL)
	{
		while (tmp != NULL)
		{
			tmp->cmd = tmp->args[0];
			tmp = tmp->next;
		}
	}
	return (0);
}

void	init_pipe(t_pars *pars)
{
	int		fd[2];
	t_pars	*tmp;

	tmp = pars;
	tmp->fd_in = 0;
	while (tmp->next != NULL)
	{
		pipe(fd);
		tmp->fd_out = fd[1];
		tmp->next->fd_in = fd[0];
		tmp = tmp->next;
	}
	tmp->fd_out = 1;
}
