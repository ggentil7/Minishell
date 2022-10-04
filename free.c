
#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_lst(t_pars *pars)
{
	t_pars	*tmp;

	tmp = pars;
	if (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
			while (tmp != NULL)
			{
				free_tab(tmp->args);
				tmp = tmp->next;
			}
			p_lstclear(pars);
		}
		else
		{
			free_tab(tmp->args);
			p_lstclear(pars);
		}
	}
	else
		return ;
}

void	free_prompt(t_pars *pars, char *buff, char *user)
{
	free_lst(pars);
	free(buff);
	free(user);
}
