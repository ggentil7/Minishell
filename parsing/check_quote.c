#include "../minishell.h"

int	is_quote(char *data, int i)
{
	int	y;

	y = 0;
	if (data[i] == '\"' /*&& check_d_c(data) == 0*/)
	{
		i++;
		y = i;
		while (data[i] != '\"')
		{
			if (data[i] == '\0')
				return (y);
			i++;
		}
	}
	if (data[i] == '\'' /*&& check_s_c(data) == 0*/)
	{
		i++;
		y = i;
		while (data[i] != '\'')
		{
			if (data[i] == '\0')
				return (y);
			i++;
		}
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
