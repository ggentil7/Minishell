
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
	user1 = ft_strjoin("\033[1;34m", user1);
	user1 = ft_strjoin(user1, "\033[1;33m@\033[1;34mminishell $ \033[0m");

	return (user1);
}

int	prompt(t_node *head)
{
	char	*buffer;
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head;
	buffer = readline(username(head));
	// if (buffer)
	// {
	// 	while (tmp)
	// 	{
	// 		printf("%d %s\n", i, tmp->data);
	// 		tmp = tmp->next;
	// 		i++;
	// 	}
	// }
	free(buffer);
	return (0);
}
