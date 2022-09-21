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
	//t_pars	*tmp;

	i = 0;
	(void)pars;
	user = username(head);
	tmp = pars;
	buffer = readline(user);
	add_history(buffer);

	data_to_lst(&tmp, buffer);
	while (tmp)
	{
		printf("%s\n", tmp->p_data);
		tmp = tmp->next;
	}
	//rl_clear_history();
	p_lstclear(&pars, NULL);
	free (buffer);


	free (user);
	free(buffer);
	return (0);
}
