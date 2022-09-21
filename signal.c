#include "minishell.h"

int	g_status;

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");

		rl_replace_line("", 0);
		rl_redisplay();
		rl_on_new_line();
	}
}
