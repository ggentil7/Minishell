/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:53:33 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/12 17:11:07 by aboymond         ###   ########.fr       */
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
	while (tmp != NULL)
	{
		env[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	i = 0;
	return (env);
}

t_node	*add_to_export_lst(t_pars *pars, t_node *node)
{
	t_node	*node_tmp;
	int		i;

	i = 1;
	node_tmp = node;
	while (node_tmp != NULL)
	{
		node_tmp = node_tmp->next;
	}
	while (pars->args[i])
	{
		node_tmp = add_list(node, ft_strdup(pars->args[i]));
		node_tmp = node_tmp->next;
		i++;
	}
	//env = args->args;
	//free_tab(args->args);
	printf("ADD_LST\n");
	return (node);
}
// char	**add_to_export_tab(t_pars *pars, t_node *env)
// {
// 	int		i;
// 	int		j;
// 	int		n;
// 	int		y;
// 	char	**env;

// 	i = 1;
// 	j = 0;
// 	y = 0;
// 	n = ft_tablen(pars->args);
// 	env = ft_calloc(sizeof(char *), n + 1);
// 	while (pars->args[i] && i < n)
// 	{
// 		while (j < (int)ft_strlen(pars->args[i]))
// 		{
// 			if (pars->args[i][j] == '=')
// 			{
// 				//printf("%p\n", node_tmp);
// 				j = (int)ft_strlen(pars->args[i]);
// 			}
// 			else if ((j + 1) == (int)ft_strlen(pars->args[i]) && y < n)
// 			{
// 				//printf("%s\n", pars->args[i]);
// 				env[y] = ft_strdup(pars->args[i]);
// 				y++;
// 			}
// 			j++;
// 		}
		
// 		j = 0;
// 		i++;
// 	}
// 	//env = args->args;
// 	//free_tab(args->args);
// 	printf("ADD_TAB\n");
// 	// if (args->args_tab != NULL)
// 	// 	tabjoin(env, args->args_tab);
// 	return (env);
// }
char	**tabjoin(char **tab, char **args)
{
	int	i;
	int	y;
	char	**tmp;

	i = 0;
	y = 0;
	tmp = ft_calloc(sizeof(char *), (ft_tablen(tab) + ft_tablen(args)) + 1);
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	while (args[y])
	{
		tmp[i] = ft_strdup(args[y]);
		i++;
		y++;
	}

	printf("SALUT TEEEEEEST\n");
	return (tmp);
}