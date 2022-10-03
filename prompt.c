
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
	if (ft_strncmp(buffer, "exit", 4) == 0)
	{
		free (buffer);
		exit (EXIT_SUCCESS);
	}
	if (buffer != NULL && buffer[0] != '\0')
		data_to_lst(&pars, buffer);
	tmp = pars;
	lst_to_tab(tmp);
	tmp = pars;
	i = -1;
	while (tmp != NULL)
	{
		while (tmp->args[++i] != NULL)
			printf("%s\n", tmp->args[i]);
		i = -1;
		tmp = tmp->next;
	}
	// tmp = pars;
	// while (tmp != NULL)
	// {
	// 	while (tmp->args[++i] != NULL)
	// 		free (tmp->args[i]);
	// 	free (tmp->args);
	// 	i = -1;
	// 	tmp = tmp->next;
	// }
	// p_lstclear(&tmp, NULL);
	tmp = pars;
	if (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
			while (tmp != NULL)
			{
				i = -1;
				while (tmp->args[++i] != NULL)
					free (tmp->args[i]);
				free (tmp->args);
				tmp = tmp->next;
			}
			printf("free 1\n");
			p_lstclear(pars);
		}
		else
		{
			i = -1;
			while (tmp->args[++i] != NULL)
				free (tmp->args[i]);
			free (tmp->args);
			printf("free 2\n");
			p_lstclear(pars);
		} 
	}
	if (buffer != NULL && buffer[0] != '\0')
		add_history(buffer);
	free (user);
	free(buffer);
	return (0);
}
