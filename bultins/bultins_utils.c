/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:53:33 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/06 19:26:07 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
	//env = env_sort(env);
	return (env);
}

int	add_to_export(t_pars *pars, t_node *node, t_args *args)
{
	t_node	*node_tmp;
	int		i;
	int		j;
	int		n;
	int		y;

	i = 1;
	j = 0;
	y = 0;
	node_tmp = node;
	n = ft_tablen(pars->args);
	args->args = ft_calloc(sizeof(char *), (n + 1));
	while (node_tmp != NULL)
	{
		node_tmp = node_tmp->next;
	}
	while (pars->args[i] && i < n)
	{
		while (j < (int)ft_strlen(pars->args[i]))
		{
			if (pars->args[i][j] == '=')
			{
				//printf("%p\n", node_tmp);
				node_tmp = add_list(node, ft_strdup(pars->args[i]));
				j = (int)ft_strlen(pars->args[i]);
				node_tmp = node_tmp->next;
			}
			else if ((j + 1) == (int)ft_strlen(pars->args[i]) && y < n)
			{
				printf("%s\n", pars->args[i]);
				args->args[y] = ft_strdup(pars->args[i]);
				y++;
			}
			j++;
		}
		
		j = 0;
		i++;
	}
	return (0);
}
char	**tabjoin(char **tab, t_args *args)
{
	int	i;
	int	y;
	char	**tmp;

	i = 0;
	y = 0;
	tmp = ft_calloc(sizeof(char *), (ft_tablen(tab) + ft_tablen(args->args) + 1));
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	while (args->args[y])
	{
		tmp[i] = ft_strdup(args->args[y]);
		i++;
		y++;
	}
	printf("SALUT TEEEEEEST\n");
	return (tmp);
}