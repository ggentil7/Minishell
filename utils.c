#include "minishell.h"

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
	return (tab);
}