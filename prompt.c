/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:53 by aboymond          #+#    #+#             */
/*   Updated: 2022/09/13 16:22:26 by aboymond         ###   ########.fr       */
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

int	prompt(char **envp)
{
	char	*buffer;

	buffer = readline(path());
	while (*envp++)
		printf("%s\n", *envp);
	if (buffer)
	{
		printf("You entered: %s\n", buffer);
		free(buffer);
	}
	return (0);
}
