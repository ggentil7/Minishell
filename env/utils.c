/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:26:22 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:26:23 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*after_egal(t_node *env, char *search)
{
	char	*tmp;

	tmp = search_env(env, search);
	if (tmp == NULL)
		return (NULL);
	return (reste(tmp));
}

int	check_env_var(char *env, char *vari)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = check_equal_env(env);
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

char	*reste(char *str)
{
	char	*res;
	int		i;
	int		y;

	i = 0;
	y = 0;
	res = NULL;
	if (str == NULL)
		return (NULL);
	while (i < (int)ft_strlen(str) && str[i] != '=')
		i++;
	if (str[i] != '=')
		return (NULL);
	i++;
	y = ft_strlen(str) - i;
	res = ft_calloc(sizeof(char), y + 1);
	y = 0;
	while (i < (int)ft_strlen(str))
	{
		res[y++] = str[i++];
	}
	return (res);
}
