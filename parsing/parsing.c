/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:21 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:25:21 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	data_to_lst(t_pars **pars, char *data)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (check_data_to_lst(data) == -1)
		return (-1);
	while (data[++i])
	{
		i = is_quote(data, i);
		if (data[i] == '|')
		{
			is_pipe(pars, data, i, j);
			j = i + 1;
			if (data[i + 1] == ' ')
			{
				while (data[i + 1] == ' ')
					i++;
				j = i + 1;
			}
		}
		if (data[i + 1] == '\0')
			is_zero(pars, data, i, j);
	}
	return (0);
}

int	check_data_to_lst(char *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data[i])
	{
		j = i;
		i = is_quote(data, i);
		if (j != i)
			i++;
		if (after_is_quote(data, i) == -1)
			return (error_quote());
		if (data[i] == '|')
			if (is_double_pipe(data, i) == -1 || check_pipe(data) == -1
				|| is_space_pipe(data, i) == -1)
				return (-1);
		if (data[i] == '\0')
			return (0);
		if (data[i] != '\'' && data[i] != '\"')
			i++;
	}
	return (0);
}

void	is_zero(t_pars **pars, char *data, int i, int j)
{
	char	*tmp;

	tmp = ft_substr(data, j, i - j + 1);
	*pars = p_add_list(*pars, tmp);
}

int	is_space(char *data)
{
	int	i;

	i = 0;
	if (data[0] == ' ')
	{
		while (data[i] == ' ')
			i++;
		if (data[i] == '\0')
			return (-1);
	}
	return (0);
}

int	is_tab(char *data)
{
	int	i;
	int	space_or_tab;

	i = 0;
	space_or_tab = 0;
	while (data[i])
	{
		if (data[i] == ' ' || data[i] == '\t')
			space_or_tab++;
		i++;
	}
	if (i == space_or_tab)
		return (-1);
	return (0);
}
