#include "minishell.h"

char	*is_dollars(char *line, t_node *env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	if (ft_strcmp(line, "$?") == 0 || ft_strcmp(line, "\"$?\"") == 0)
		return (line);
	tmp = join_dollars(env, line, tmp, i);
	return (tmp);
}

int	is_dollars_or_quote(char *line, int i)
{
	while (line[i] != '$' && i < (int)ft_strlen(line))
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\'' && i < (int)ft_strlen(line))
				i++;
			if (line[i] == '\'')
				i++;
		}
		else
			i++;
	}
	return (i);
}

char	*join_dollars(t_node *env, char *line, char *tmp, int i)
{
	char	*tmp2;
	char	*tmp3;
	int		j;

	j = 0;
	while (i < (int)ft_strlen(line))
	{
		j = i;
		i = is_dollars_or_quote(line, i);
		if (i > j)
		{
			tmp3 = ft_substr(line, j, i - j);
			tmp = ft_strjoin_free(tmp, tmp3);
		}
		j = i;
		while (line[i] && line[i + 1] && ft_isalpha_under_s(line[i + 1]) == 1)
			i++;
		if (i > j)
		{
			tmp2 = ft_substr(line, j+1, i - j);
			if (after_egal(env, tmp2) != NULL)
				tmp = ft_strjoin_free(tmp, after_egal(env, tmp2));
			free (tmp2);
		}
		i++;
	}
	return (tmp);
}