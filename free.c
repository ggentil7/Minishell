
#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (i < ft_tablen(tab) + 1)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_lst_pars(t_pars *pars)
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

void	free_prompt(t_pars *pars, t_prompt *prompt)
{
	free_lst_pars(pars);
	free(prompt->buffer);
	free(prompt->user);
}

void	free_lst_node(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	if (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
			while (tmp != NULL)
			{
				if (tmp->args != NULL)
					free_tab(tmp->args);
				tmp = tmp->next;
			}
			lstclear(node);
		}
		else
		{
			if (tmp->args != NULL)
				free_tab(tmp->args);
			lstclear(node);
		}
	}
	else
		return ;
}
