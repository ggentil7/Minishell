/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:27:14 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:27:15 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_export(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		printf("\033[1;31mdeclare -x \033[0m");
		i = print_export2(env, i);
		printf("\n");
	}
	return (0);
}

int	print_export2(char **env, int i)
{
	int	j;

	j = -1;
	printf("\033[1;94m");
	while (++j < (int)ft_strlen(env[i]))
	{
		printf("%c", env[i][j]);
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
		}
	}
	return (i);
}

int	print_env(t_node *env)
{
	t_node	*tmp;
	int		i;

	i = -1;
	tmp = env;
	while (tmp != NULL)
	{
		i = -1;
		while (++i < (int)ft_strlen(tmp->data))
		{
			if (tmp->data[i] == '\0')
			{
				i = (int)ft_strlen(tmp->data) + 1;
			}
			if (tmp->data[i] == '=')
			{
				printf("%s\n", tmp->data);
				i = (int)ft_strlen(tmp->data) + 1;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
