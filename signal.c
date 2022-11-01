#include "minishell.h"

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		write (1, "\n", 1);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_signal(struct termios *saved)
{
	hide_key(saved);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigint);
}

void	hide_key(struct termios *saved)
{
	struct termios	attr;

	tcgetattr(STDIN_FILENO, &attr);
	tcgetattr(STDIN_FILENO, saved);
	attr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}
