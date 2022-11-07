#include "../minishell.h"

char	*after_egal(t_node *env, char *search)
{
	char	*tmp;

	tmp = search_env(env, search);
	if (tmp == NULL)
		return (NULL);
	return (reste(tmp));
}
