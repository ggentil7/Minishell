
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
	new = ft_calloc(sizeof(char), (int)ft_strlen(data) - compte_quote(data) + 1);
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

// int	check_s_q(char *line)
// {
// 	int	i;
// 	int	compt;

// 	i = -1;
// 	compt = 0;
// 	while (line[++i])
// 	{
// 		printf("avant line s_q [%c], i = %d\n", line[i], i);
// 		if (line[i] == 39)
// 		{
// 			compt++;
// 			i = is_quote(line, i);
// 			i--;
// 		}
// 		printf("line s_q [%c], i = %d\n", line[i], i);
// 		printf("compt s_q = %d\n", compt);
// 	}
// 	if (compt % 2 == 1)
// 		return (1);
// 	return (0);
// }

// int	check_d_q(char *line)
// {
// 	int	i;
// 	int	compt;

// 	i = 0;
// 	compt = 0;
// 	while (line[i])
// 	{
// 		printf("avant line d_q [%c], i = %d\n", line[i], i);
// 		if (line[i] == 34)
// 		{
// 			compt++;
// 			i = is_quote(line, i);
// 			i--;
// 		}
// 		printf("line d_q [%c], i = %d\n", line[i], i);
// 		printf("compt d_q = %d\n", compt);
// 		i++;
// 	}
// 	if (compt % 2 == 1)
// 		return (1);
// 	return (0);
// }
