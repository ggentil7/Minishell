# include "../minishell.h"

// int	redirection_args(t_pars *pars)
// {
// 	int	i;
// 	int	y;

// 	i = 0;
// 	y = 0;
// 	while (pars)
// 	{
// 		while (pars->args[i])
// 		{
// 			while (pars->args[i][y])
// 			{
// 				if (pars->args[i][y] == '<')
// 				{
// 					if(pars->args[i][y + 1] == '<')

// 					else

// 				}
// 				else if (pars->args[i][y] == '>')
// 				{
// 					if(pars->args[i][y + 1] == '>')

// 					else

// 				}

// 			}
// 		}
// 		pars = pars->next;
// 	}
// }

int	redirection_tab(t_pars *pars)
{
	t_pars *tmp;
	int	i;
	int	y;
	int	j;

	tmp = pars;
	i = 0;
	y = 0;
	while (tmp != NULL)
	{
		while (tmp->args[i])
		{
			while (y < (int)ft_strlen(tmp->args[i]))
			{
				if (tmp->args[i][y] == '<' || tmp->args[i][y] == '>')
				{
					tmp->redir = tmp->args[i];
					j = i;
					break ;
				}
				y++;
			}
			y = 0;
			i++;
		}
		printf("redir = %s, i = %d, y = %d\n", tmp->redir, i, y);
		redo_tab(*tmp, j);
		tmp = tmp->next;
		i = 0;
	}
	return (0);
}

int	redo_tab(t_pars pars, int i)
{
	int	y;
	int	j;
	int	k;
	char	**tmp;

	y = 0;
	j = 0;
	k = 0;
	tmp = malloc(sizeof(char **) * (ft_tablen(pars.args) - 1));
	while (pars.args[j])
	{
		printf("avant j = %d, y = %d\n\n", j, y);
		if (j < i)
		{
			tmp[y] = pars.args[j];
			j++;
			y++;
		}
		else if (j > i)
		{
			tmp[y] = pars.args[j];
			j++;
			y++;
		}
		else
		{
			j++;
		}
		printf("j = %d, y = %d k = %d\n\n", j, y, k);
	}
	y = 0;
	printf("tab = %d, tab args = %d\n", ft_tablen(tmp), ft_tablen(pars.args));
	while (y < ft_tablen(tmp))
	{
		printf("real tmp = %s\n", tmp[y]);
		y++;
	}
	// free_tab(pars.args);
	// pars.args = tmp;
	return (0);
}