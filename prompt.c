/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:53 by aboymond          #+#    #+#             */
/*   Updated: 2022/09/13 19:31:16 by aboymond         ###   ########.fr       */
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

// char	*username(char **envp)
// {
// 	char	*user;

// 	user = envp[0];
// 	user = ft_split(user, '=');
// 	user = ft_strjoin(user, "@minishell :");
// 	return (user);
// }

int	prompt(char **envp)
{
	char	*buffer;
	int		i;

	i = -1;
	buffer = readline(path());
	if (ft_strncmp(buffer, "env", 3) == 0)
	{
		while (envp[++i])
		{
			printf("%s\n", envp[i]);
		}
		free(buffer);
	}
	return (0);
}
