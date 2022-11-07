
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
	if (search_env(head, "USER") == NULL)
		user = ft_strdup("🖕🖕🖕🖕");
	else
	{
		user = search_env(head, "USER");
		user1 = reste(user);
		user = ft_strjoin("\033[1;34m", user1);
		free (user1);
	}
	user1 = ft_strjoin(user, at);
	free (user);
	user = ft_strjoin(user1, mini);
	free (user1);
	user1 = ft_strjoin(user, dol);
	free (user);
	return (user1);
}

int	prompt_(t_node *head, t_pars *pars, t_prompt *prompt)
{
	t_pars	*tmp;

	prompt->user = username(head);
	prompt->buffer = readline(prompt->user);
	
	if (!prompt->buffer)
	{
		printf("exit\n");
		free_prompt(pars, prompt);
		exit (1) ;
	}
	if (prompt->buffer != NULL && prompt->buffer[0] != '\0')
		add_history(prompt->buffer);
	if (prompt->buffer != NULL && prompt->buffer[0] != '\0' && is_tab(prompt->buffer) != -1 && check_chev(prompt->buffer) != -1)
	{
		if (data_to_lst(&pars, prompt->buffer) == -1)
		{
			free (prompt->buffer);
			free (prompt->user);
			return (1);
		}
	}
	tmp = pars;
	lst_to_tab(tmp, head);
	if (tmp != NULL)
	{
		init_pipe(tmp);
		cmd(tmp, head, prompt);
	}
	free_prompt(pars, prompt);
	return (0);
}

void	print_prompt(t_pars *pars)
{
	t_pars	*tmp;
	int		i;

	i = -1;
	tmp = pars;
	while (tmp != NULL)
	{
		while (tmp->args[++i] != NULL)
			printf("%s\n", tmp->args[i]);
		i = -1;
		tmp = tmp->next;
	}
}

// int	prompt(t_node *head, t_pars *pars)
// {
// 	t_pars	*tmp;
// 	char	*buffer;
// 	char	*user;

// 	// add_history("cat << EOF > toto.txt");
// 	user = username(head);
// 	buffer = readline(user);
	
// 	if (!buffer)
// 	{
// 		printf("exit\n");
// 		free_prompt(pars, buffer, user);
// 		exit (1) ;
// 	}
// 	if (ft_strcmp(buffer, "exit") == 0)
// 	{
// 		printf("exit\n");
// 		free_prompt(pars, buffer, user);
// 		exit (EXIT_SUCCESS);
// 	}
// 	if (buffer != NULL && buffer[0] != '\0')
// 		add_history(buffer);
// 	if (buffer != NULL && buffer[0] != '\0' && is_tab(buffer) != -1 && check_chev(buffer) != -1)
// 	{
// 		if (data_to_lst(&pars, buffer) == -1)
// 			return (1);
// 	}
// 	tmp = pars;
// 	lst_to_tab(tmp);
// 	if (tmp != NULL)
// 		init_pipe(tmp);
// 	tmp = pars;
// 	if (tmp != NULL)
// 		cmd(tmp, head);
// 	//print_prompt(tmp);
// 	free_prompt(pars, buffer, user);
// 	return (0);
// }