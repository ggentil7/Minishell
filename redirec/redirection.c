# include "../minishell.h"



int	redirection_tab(t_pars *pars)
{
	t_pars *tmp;
	int	i;

	tmp = pars;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->args[i])
		{
			if (chevron_detect(tmp, tmp->args[i], i) == -1)
				i++;
			printf("redirect tmp->args[%d] = %s\n", i, tmp->args[i]);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	chevron_detect(t_pars *pars, char *tab, int i)
{
	if (ft_strcmp(tab, ">") == 0)
	{
		del_chevron_more(pars, i);
		chevron_d_simple(pars, i);
	}
	else if (ft_strcmp(tab, "<") == 0)
	{
		del_chevron_more(pars, i);
		chevron_g_simple(pars, i);
	}
	else if (ft_strcmp(tab, ">>") == 0)
	{
		del_chevron_more(pars, i);
		chevron_d_double(pars, i);
	}
	else if (ft_strcmp(tab, "<<") == 0)
	{
		del_chevron_more(pars, i);
		//chevron_g_double(pars, tab, i);
	}
	else
		return (-1);
	return (0);
}

int	del_chevron_more(t_pars *pars, int i)
{
	int	j;

	j = i + 1;
	while (pars->args[j])
	{
		pars->args[i] = pars->args[j];
		//printf("args chevron = %s\n", pars->args[i]);
		i++;
		j++;
	}
	pars->args[i] = NULL;
	return (0);
}

