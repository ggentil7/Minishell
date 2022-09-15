
#include "minishell.h"

char	*path(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	pwd = ft_strjoin(pwd, " : ");
	return (pwd);
}

char	*username(t_node *head)
{
	char	*user;
	char	*user1;

	user = search_env(head, "USER");
	user1 = reste(user);
	user = ft_strjoin("\033[1;34m", user1);
	free(user1);
	user1 = ft_strjoin(user, "\033[1;35m@\033[1;34mMinishell $ \033[0m");
	free (user);
	return (user1);
}

int	prompt(t_node *head, t_pars *pars)
{
	//t_pars	*tmp;
	char	*buffer;
	char	*user;
	int		i;

	i = 0;
	(void)pars;
	user = username(head);
	//tmp = pars;
	buffer = readline(user);
	add_history(buffer);
	//rl_clear_history();
	free (buffer);
	free (user);
	return (0);
}
