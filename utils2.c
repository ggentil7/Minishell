#include "./minishell.h"

int	is_dollars(char *tab, t_pars *pars, t_node *env)
{
	int	y;
	int	j;
	char *tmp;

	y = 0;
	j = compt_doll(tab);
	if ((tab[y] == '\"' && tab[y + 1] == '$') || tab[y] == '$')
	{
		if (j > 1)
		{
			while (tab[y])
			{
				if (tab[y] == '$')
					return (-1);
				y++;
			}
		}
		else
		{
			y++;
			tmp = ft_substr(tab, y, ft_strlen(tab));
			pars->doll_tab = after_egal(env, tmp);
		}
	}
	else
		return (-1);
	return (0);
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





