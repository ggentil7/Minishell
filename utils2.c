#include "./minishell.h"

void	is_dollars(char *tab, int i, t_pars *pars)
{
	int	y;

	y = 0;
	if ((tab[y] == '\"' && tab[y + 1] == '$') || tab[y] == '$')
	{
		pars->doll_flag[i] = 1;
	}
	else
		pars->doll_flag[i] = 0;
}

char	*remove_dollars(char *tab)
{
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	y = 1;
	tmp = ft_calloc(ft_strlen(tab), sizeof(char));
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