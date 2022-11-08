
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

	tmp = head;
	sea = NULL;
	while (tmp)
	{
		if (check_env(tmp->data, search) == 1)
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
			sea = tmp->data;
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
	while (tmp != NULL)
	{
		if (check_env(tmp->data, search) == 1)
		{
			lstclear_cell(head, search);
			return (NULL);
		}
		else
			tmp = tmp->next;
	}
	return (NULL);
}

int	check_env(char *env, char *vari)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = check_equal(env);
	while (tmp[i] && vari[i] == env[i])
	{
		// printf("env = [%c] - %s, vari = [%c] - %s\n", env[i], env, vari[i], vari);
		if (tmp[i + 1] == '\0' && vari[i + 1] == '\0')
		{
			free (tmp);
			return (1);
		}
		i++;
	}
	free (tmp);
	return (0);
}

int	check_env_var(char *env, char *vari)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = check_equal_env(env);
	while (tmp[i] && vari[i] == env[i])
	{
		// printf("env = [%c] - %s, vari = [%c] - %s\n", env[i], env, vari[i], vari);
		if (tmp[i + 1] == '\0' && vari[i + 1] == '\0')
		{
			free (tmp);
			return (1);
		}
		i++;
	}
	free (tmp);
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
	while (i < (int)ft_strlen(str) && str[i] != '=')
		i++;
	if (str[i] != '=')
		return (NULL);
	i++;
	y = ft_strlen(str) - i;
	res = ft_calloc(sizeof(char), y + 1);
	y = 0;
	while (i < (int)ft_strlen(str))
	{
		res[y++] = str[i++];
	}
	return (res);
}
