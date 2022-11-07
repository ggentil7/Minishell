
#include "../minishell.h"

void	env_cpy(t_node **node, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		*node = add_list(*node, ft_strdup(envp[i]));
		i++;
	}
}

char	*search_env_var(t_node *head, char *search)
{
	t_node	*tmp;
	char	*sea;
	int		i;

	tmp = head;
	sea = NULL;
	i = 0;
	while (tmp)
	{	
		i++;
		if (ft_strncmp(tmp->data, search, ft_strlen(search)) == 0)
		{
			sea = tmp->data;
			return (sea);
		}
		tmp = tmp->next;
	}
	return (NULL);
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
			sea = ft_strdup(tmp->data);
			return (sea);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	*del_env(t_node *head, char *search) /* trouver la bonne ligne dans envp */
{
	t_node	*tmp;
	char	*sea;

	tmp = head;
	sea = NULL;
	while (tmp)
	{
		if (check_env(tmp->data, search) == 1)
		{
			sea = ft_strdup(tmp->data);
			lstclear_cell(head, tmp->data);
			return (sea);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	check_env(char *env, char *vari)
{
	int	i;

	i = 0;
	while (env[i] && vari[i] == env[i])
	{
		if (env[i + 1] == '=' || vari[i + 1] == '\0')
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
	if (str == NULL)
		return (NULL);
	while (str[i] != '=' && str[i])
		i++;
	i++;
	y = ft_strlen(str) - i;
	res = ft_calloc(sizeof(char), y + 1);
	y = 0;
	while (str[i])
	{
		res[y++] = str[i++];
	}
	return (res);
}
