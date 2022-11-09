/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:38:27 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:39:35 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node			*node;
	t_pars			*pars;
	t_prompt		*prompt;
	struct termios	saved;

	(void)argc;
	(void)argv;
	node = NULL;
	pars = NULL;
	prompt = ft_calloc(1, sizeof(t_prompt));
	env_cpy(&node, envp);
	while (1)
	{
		handle_signal(&saved);
		prompt_(node, pars, prompt);
		tcsetattr(STDIN_FILENO, TCSANOW, &saved);
	}
	return (0);
}
