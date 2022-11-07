#include "../minishell.h"

int	error_quote(void)
{
	ret("syntax error near unexpected token quote", 258, 0);
	return (-1);
}
