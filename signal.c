/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:22:35 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:22:36 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write (1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_signal(struct termios *saved)
{
	hide_key(saved);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	hide_key(struct termios *saved)
{
	struct termios	attr;

	tcgetattr(STDIN_FILENO, &attr);
	tcgetattr(STDIN_FILENO, saved);
	attr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}

void	handle_sigquit(int sig)
{
	if (sig == SIGINT)
	{
		write (1, "\n", 1);
	}
	if (sig == SIGQUIT)
	{
		printf("Quit: 3\n");
		rl_on_new_line();
	}
}
