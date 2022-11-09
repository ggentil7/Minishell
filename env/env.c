/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:26:02 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:26:02 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*del_env(t_node *head, char *search)
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
	int		i;
	char	*tmp;

	i = 0;
	tmp = check_equal(env);
	while (tmp[i] && vari[i] == env[i])
	{
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
