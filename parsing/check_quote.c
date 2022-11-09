/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:24:44 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:24:47 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remove_quote(char *data)
{
	int		i;
	int		j;
	int		k;
	int		*quote;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	quote = init_tab_compt_quote(data);
	new = ft_calloc(sizeof(char), (int)ft_strlen(data)- compte_quote(data) + 1);
	while (data[i])
	{
		if (quote[k] != i)
			new[j++] = data[i++];
		else
		{
			k++;
			i++;
		}
	}
	free (quote);
	return (new);
}

int	is_quote(char *data, int i)
{
	int	j;

	j = 0;
	if (data[i] == '\'')
	{
		j = i;
		i++;
		i = is_s_quote(data, i);
		if (i == -1)
			return (j);
	}
	if (data[i] == '\"')
	{
		j = i;
		i++;
		i = is_d_quote(data, i);
		if (i == -1)
			return (j);
	}
	return (i);
}

int	is_s_quote(char *data, int i)
{
	while (data[i] != '\'')
	{
		if (data[i] == '\0')
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

int	is_d_quote(char *data, int i)
{
	while (data[i] != '\"')
	{
		if (data[i] == '\0')
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

int	after_is_quote(char *data, int i)
{
	if (data[i] == '\'')
	{
		i++;
		while (data[i] != '\'')
		{
			if (data[i] == '\0')
				return (-1);
			i++;
		}
		if (data[i] == '|')
			return (-1);
	}
	if (data[i] == '\"')
	{
		i++;
		while (data[i] != '\"')
		{
			if (data[i] == '\0')
				return (-1);
			i++;
		}
		if (data[i] == '|')
			return (-1);
	}
	return (0);
}
