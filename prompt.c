
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
	char	*at;
	char	*mini;
	char	*dol;

	dol = "\033[1;35m $ \033[0m";
	mini = "\033[1;34mMinishell\033[0m";
	at = "\033[0m\033[1;35m@\033[0m";
	user = search_env(head, "USER");
	user1 = reste(user);
	user = ft_strjoin("\033[1;34m", user1);
	free (user1);
	user1 = ft_strjoin(user, at);
	free (user);
	user = ft_strjoin(user1, mini);
	free (user1);
	user1 = ft_strjoin(user, dol);
	free (user);
	return (user1);
}

int	prompt(t_node *head, t_pars *pars)
{
	t_pars	*tmp;
	char	*buffer;
	char	*user;
	int		i;

	i = -1;
	//add_history(ft_strdup("\"salut\" | ouais | 'jj'\"pouet\" | kzgfhio"));
	user = username(head);
	buffer = readline(user);
	if (buffer != NULL && buffer[0] != '\0')
		data_to_lst(&pars, buffer);
	tmp = pars;
	lst_to_tab(tmp);
	while (tmp != NULL)
	{
		while (tmp->args[++i] != NULL)
			printf("%s\n", tmp->args[i]);
		i = -1;
		tmp = tmp->next;
	}
	tmp = pars;
	while (tmp != NULL)
	{
		while (tmp->args[++i] != NULL)
			free (tmp->args[i]);
		free (tmp->args);
		i = -1;
		tmp = tmp->next;
	}
	tmp = pars;
	p_lstclear(&tmp, NULL);
	while (pars != NULL)
	{
		while (pars->args[++i] != NULL)
			free (pars->args[i]);
		free (pars->args);
		i = -1;
		pars = pars->next;
	}
	p_lstclear(&pars, NULL);


	if (buffer != NULL && buffer[0] != '\0')
		add_history(buffer);
	free (user);
	free(buffer);
	return (0);
}
