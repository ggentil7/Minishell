
#include "../minishell.h"

void	env_cpy(t_node **node, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		//printf("envp[%d] = %s\n", i, envp[i]);
		*node = add_list(*node, envp[i]);
		i++;
	}
}

char	*search_env(t_node *head, char *search) /* trouver la bonne ligne dans envp */
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

int	check_env(char *env, char *vari)  /* validerr la bonne ligne */
{
	int	i;

	i = 0;
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

char	*reste(char *str)  /* fonction pour recuperer le reste apres le  = */
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
	res = ft_calloc(sizeof(char), y + 1);
	y = 0;
	while (str[i])
	{
		res[y++] = str[i++];
	}
	return (res);
}
