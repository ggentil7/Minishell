/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:26:54 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:26:55 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bultin_pwd(t_pars *pars)
{
	char	*path;
	int		i;

	(void)pars;
	i = ft_tablen(pars->args);
	if (i > 1)
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		return (1);
	}
	else
	{
		path = getcwd(NULL, 0);
		ft_putstr_fd(path, 1);
		write(1, "\n", 1);
		free(path);
	}
	return (0);
}
