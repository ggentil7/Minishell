/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:27:21 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:27:23 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**env_sort(char **env)
{
	int		i;
	int		j;
	int		n;
	char	*tmp;

	i = 0;
	j = 0;
	n = ft_tablen(env);
	while (j < n)
	{
		i = j + 1;
		while (i < n)
		{
			if (ft_strcmp(env[j], env[i]) > 0)
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

t_node	*add_to_export_lst(t_pars *pars, t_node *node, char *args)
{
	(void)pars;
	add_list(node, ft_strdup(args));
	return (node);
}
