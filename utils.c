/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:21:59 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:22:03 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*init_tab_compt_quote(char *data)
{
	int	i;
	int	j;
	int	k;
	int	*quote;

	j = 0;
	i = -1;
	k = 0;
	quote = ft_calloc(sizeof(int), compte_quote(data) + 1);
	while (data[++i])
	{
		if (data[i] == '\'' || data[i] == '\"')
		{
			j = i;
			quote[k] = j;
			k++;
			i = is_quote(data, i);
			quote[k] = i;
			k++;
		}
	}
	return (quote);
}

int	compte_quote(char *data)
{
	int	i;
	int	j;
	int	compt;

	i = -1;
	j = 0;
	compt = 0;
	while (data[++i])
	{
		j = i;
		i = is_quote(data, i);
		if (j != i)
			compt += 2;
	}
	return (compt);
}

int	ft_set(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split_pipe(char *s, char c, t_pars *pars, t_node *env)
{
	char	**tab;
	int		i;
	int		j;
	int		tmp;

	j = 0;
	i = 0;
	tab = ft_calloc(sizeof(char *), ft_set(s, c) + 1);
	while (tab && s[i])
	{
		while (s[i] && s[i] == c)
		{
			i = is_quote(s, i);
			i++;
		}
		tmp = i;
		while (s[i] && s[i] != c)
		{
			i = is_quote(s, i);
			i++;
		}
		if (tmp != i)
			tab[j++] = ft_substr(s, tmp, i - tmp);
	}
	return (split_to_remove(tab, pars, env));
}

char	**split_to_remove(char **tab, t_pars *pars, t_node *env)
{
	int		i;
	char	**tab2;
	char	*tmp;

	i = 0;
	(void)pars;
	tab2 = ft_calloc(sizeof(char *), ft_tablen(tab) + 1);
	while (tab[i])
	{
		if (compte_quote(tab[i]) == 0)
		{
			tab2[i] = is_dollars(tab[i], env);
		}
		else
		{
			tmp = is_dollars(tab[i], env);
			tab2[i] = remove_quote(tmp);
			free (tmp);
		}
		i++;
	}
	free_tab(tab);
	return (tab2);
}
