#include "./minishell.h"

int	is_env_char(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'));
}

char	*parse_dollar(char *line, unsigned int *i, t_node *env)
{
	char	*name;
	char	*value;
	unsigned int	j;

	j = 0;
	while (*i + j < ft_strlen(line) - 1 && is_env_char(line[*i + j]))
		j++;
	name = ft_substr(line, *i, *i + j);
	*i = *i + j;
	value = after_egal(env, name);
	if (value == NULL)
		value = ft_strdup("");
	return (value);
}

char	*is_dollars(char *line, t_pars *pars, t_node *env)
{
	unsigned int		i;
	unsigned int		j;
	int		k;
	char	**tab;

	(void)pars;
	tab = ft_calloc(1000, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 1000)
	{
		tab[i] = ft_calloc(10000, sizeof(char));
		if (!tab[i])
			return (NULL);
		i++;
	}

	i = 0;
	j = 0;
	k = 0;

	
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '$' && i < ft_strlen(line) - 1)
			tab[j][k++] = line[i++];
		else
		{
			j++;
			i++;
			/*if (line[i] == '?')
				parse_return_value();*/
			free(tab[j]);
			tab[j++] = parse_dollar(line, &i, env);
		}
		printf("debug: %c\n", line[i]);
	}
	
	i = 0;
	while (tab[i][0] != '\0')
	{
		printf("%s\n", tab[i]);
		i++;
	}
	//return (join_tab(tab));
	return (NULL);
}

int	compt_doll(char *tab)
{
	int	y;
	int	j;
	int	compt;

	y = 0;
	j = 0;
	compt = 0;
	if ((tab[y] == '\"' && tab[y + 1] == '$') || tab[y] == '$')
	{
		while (tab[y])
		{
			if (tab[y] == '$')
				compt++;
			y++;
		}
	}
	else
		return (0);
	return (compt);
}

char	*remove_dollars(char *tab)
{
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	y = 1;
	tmp = ft_calloc((int)ft_strlen(tab), sizeof(char));
	while (tab[y])
	{
		tmp[i] = tab[y];
		i++;
		y++;
	}
	return (tmp);
}

int check_equal(char *str)
{
	int i = -1;

	while (str[++i])
		if (str[i] == '=')
			return (1);
	return (0);
}

int	check_chev(char *chevr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (chevr[i])
	{
		if (chevr[i] == '>' || chevr[i] == '<')
			j++;
		i++;
	}
	if (i == j)
	{
		ret("syntax error near unexpected token `newline'", 258, 0);
		return (-1);
	}
	return (0);
}





