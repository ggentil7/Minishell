
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

static int	ft_set(char *s, char c)
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

char	**ft_split_pipe(char *s, char c)
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
	return (split_to_remove(tab));
}

char	**split_to_remove(char **tab)
{
	int		i;
	char	**tab2;

	i = 0;
	tab2 = ft_calloc(sizeof(char *), ft_tablen(tab) + 1);
	while (tab[i])
	{
		if (compte_quote(tab[i]) == 0)
		{
			tab2[i] = ft_strdup(tab[i]);
		}
		else
		{
			tab2[i] = remove_quote(tab[i]);
		}
		i++;
	}
	i = -1;
	while (tab[++i])
		free (tab[i]);
	free (tab);
	return (tab2);
}

// char	**ft_split_quote(char *s, char c)
// {
// 	char	**tab;
// 	int		i;
// 	int		j;
// 	int		tmp;

// 	j = 0;
// 	i = 0;
// 	s = remove_quote(s);
// 	tab = ft_calloc(sizeof(char *), ft_set(s, c) + 1);
// 	while (tab && s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 		{
// 			i++;
// 		}
// 		tmp = i;
// 		while (s[i] && s[i] != c)
// 		{
// 			i++;
// 		}
// 		if (tmp != i)
// 			tab[j++] = ft_substr(s, tmp, i - tmp);
// 	}
// 	return (tab);
// }
