/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:30 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:25:32 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_pipe(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[0] == '|')
		{
			ret("syntax error near unexpected token `|'", 258, 0);
			return (-1);
		}
		i = is_quote(data, i);
		if (data[i] == '|')
		{
			if (is_double_pipe(data, i) == -1 || is_space_pipe(data, i) == -1
				|| is_bs_pipe(data, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	is_pipe(t_pars **pars, char *data, int i, int j)
{
	char	*tmp;

	tmp = ft_substr(data, j, i - j);
	*pars = p_add_list(*pars, tmp);
}

int	is_double_pipe(char *data, int i)
{
	if (data[i + 1] == '|')
	{
		ret("syntax error near unexpected token `|'", 258, 0);
		return (-1);
	}
	return (0);
}

int	is_bs_pipe(char *data, int i)
{
	if (data[i + 1] == '\0')
	{
		ret("syntax error near unexpected token `|'", 258, 0);
		return (-1);
	}
	return (0);
}

int	is_space_pipe(char *data, int i)
{
	if (data[i + 1] == ' ')
	{
		i++;
		while (data[i] == ' ')
		{
			if (data[i + 1] == '|' || data[i + 1] == '\0')
			{
				ret("syntax error near unexpected token `|'", 258, 0);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}
