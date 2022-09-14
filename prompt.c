/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:53 by aboymond          #+#    #+#             */
/*   Updated: 2022/09/14 16:47:52 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	pwd = ft_strjoin(pwd, " : ");
	return (pwd);
}

char	*username(char **envp)
{
	char	*user;

	user = envp[0];
	user = ft_split(user, '=');
	user = ft_strjoin(user, "@minishell :");
	return (user);
}

int	prompt(t_node *head)
{
	char	*buffer;
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head;
	buffer = readline(path());
	if (buffer)
	{
		while (tmp)
		{
			printf("%d %s\n", i, tmp->data);
			tmp = tmp->next;
			i++;
		}
	}
	free(buffer);
	return (0);
}
