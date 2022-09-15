
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
	user1 = ft_strjoin(user, "\033[1;33m@\033[1;34mminishell $ \033[0m");
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
	user = username(head);
	//tmp = pars;
	//(void)pars;
	buffer = readline(user);
	free (user);
	if (buffer)
	{
		tk_data(&pars, buffer);
		while (pars)
		{
			printf("%d %s\n", i, pars->p_data);
			pars = pars->next;
			i++;
		}
	}
	free(buffer);
	return (0);
}
