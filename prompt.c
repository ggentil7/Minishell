/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:53 by aboymond          #+#    #+#             */
/*   Updated: 2022/09/08 11:47:09 by piow00           ###   ########.fr       */
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

int	prompt()
{
	char	*buffer;

	buffer = readline(path());
	if (buffer)
	{
		printf("You entered: %s\n", buffer);
		free(buffer);
	}
	return (0);
}