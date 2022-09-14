
#include "minishell.h"

void	env_cpy(t_node **node, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		*node = add_list(*node, envp[i]);
		i++;
	}
}

char	*search_env(t_node *head, char *search)
{
	t_node	*tmp;
	char	*sea;

	tmp = head;
	sea = NULL;
	while (tmp)
	{
		if (check_env(tmp->data, search) == 1)
		{
			sea = tmp->data;
			return (tmp->data);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int		check_env(char *env, char *vari)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (env[i] && vari[i] == env[i])
	{
		if (env[i + 1] == '=')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*reste(char *str)
{
	char	*res;
	int		i;
	int		y;

	i = 0;
	y = 0;
	res = NULL;
	while (str[i] != '=')
		i++;
	i++;
	y = ft_strlen(str) - i;
	res = malloc(sizeof(char *) * y);
	y = 0;
	while (str[i])
	{
		res[y++] = str[i++];
	}
	return (res);
}
