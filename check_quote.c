#include "minishell.h"

int	is_quote(char *data, int i)
{
	if (data[i] == '\"')
	{
		i++;
		while (data[i] != '\"')
			i++;
	}
	if (data[i] == '\'')
	{
		i++;
		while (data[i] != '\'')
			i++;
	}
	return (i);
}

int	check_s_c(char *line)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (line[i])
	{
		if (line[i] == 39)
			compt++;
		i++;
	}
	if (compt % 2 == 1)
		return (1);
	return (0);
}

int	check_d_c(char *line)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (line[i])
	{
		if (line[i] == 34)
			compt++;
		i++;
	}
	if (compt % 2 == 1)
		return (1);
	return (0);
}
