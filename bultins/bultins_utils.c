#include "../minishell.h"

char	**env_sort(char **env)
{
	int i;
	int j;
	int n;
	char *tmp;

	i = 0;
	j = 0;
	n = ft_tablen(env);
	while (j < n)
	{
		i = j + 1;
		while (i < n)
		{
			if (strcmp(env[j], env[i]) > 0)
			{
				tmp = env[j];
				env[j] = env[i];
				env[i] = tmp;
			}
			i++;
		}
		j++;
	}
	return (env);
}

char	**env_to_tab(t_node *node)
{
	t_node	*tmp;
	char	**env;
	int		i;

	i = 0;
	tmp = node;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	env = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	tmp = node;
	while (node != NULL)
	{
		env[i] = node->data;
		node = node->next;
		i++;
	}
	env[i] = NULL;
	i = 0;
	return (env);
}

int	print_export(char **env)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (env[++i])
	{
		printf("\033[1;31mdeclare -x \033[0m");
		j = 0;
		while (j < (int)ft_strlen(env[i]))
		{
			printf("\033[1;94m%c\033[0m", env[i][j]);
			if (env[i][j] == '=')
			{
				j++;
				printf("\033[1;92m\"");
				while (env[i][j] != '\0')
				{
					printf("%c", env[i][j]);
					j++;
				}
				printf("\"\033[0m");
				printf("\n");
			}
			j++;
		}
	}
	return (0);
}

int	add_to_export(t_pars *pars, t_node *node)
{
	t_node	*node_tmp;
	// t_pars	*pars_tmp;
	int		i;
	int		j;
	int		n;
	int		y;

	i = 1;
	j = 0;
	y = 0;
	n = ft_tablen(pars->args);
	node_tmp = node;
	while (node_tmp != NULL)
		node_tmp = node_tmp->next;
	while (pars->args[i])
	{
		while (j < (int)ft_strlen(pars->args[i]))
		{
			if (pars->args[i][j] == '=')
			{
				node_tmp = add_list(node_tmp, pars->args[i]);
				printf("%s\n", node_tmp->data);
				j = (int)ft_strlen(pars->args[i]);
			}
			// else if ((j + 1) == (int)ft_strlen(pars->args[i]))
			// {
			// 	node->args[y] = ft_strdup(pars->args[i]);
			// 	y++;
			// }
			j++;
		}
		i++;
	}
	return (0);
}