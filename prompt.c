/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:55:53 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 18:12:03 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	pwd = ft_strjoin(pwd, " : ");
	return (pwd);
}

char	*username(t_node *head)
{
	char	*user1;
	char	*at;
	char	*mini;
	char	*dol;

	dol = "\033[1;35m $ \033[0m";
	mini = "\033[1;34mMinishell\033[0m";
	at = "\033[0m\033[1;35m@\033[0m";
	user1 = username2(head, at, mini, dol);
	return (user1);
}

char	*username2(t_node *head, char *at, char *mini, char *dol)
{
	char	*user;
	char	*user1;

	if (search_env(head, "USER") == NULL)
		user = ft_strdup("🖕🖕🖕🖕");
	else
	{
		user = search_env(head, "USER");
		user1 = reste(user);
		if (user1 != NULL)
		{
			user = ft_strjoin("\033[1;34m", user1);
			free (user1);
		}
		else
			user = ft_strjoin("\033[1;34m", "💩💩💩💩");
	}
	user1 = ft_strjoin(user, at);
	free (user);
	user = ft_strjoin(user1, mini);
	free (user1);
	user1 = ft_strjoin(user, dol);
	free (user);
	return (user1);
}

int	prompt_(t_node *head, t_pars *pars, t_prompt *prompt)
{
	t_pars	*tmp;

	prompt->user = username(head);
	prompt->buffer = readline(prompt->user);
	exit_ctrld(prompt, pars);
	if (prompt->buffer != NULL && prompt->buffer[0] != '\0')
		add_history(prompt->buffer);
	if (prompt->buffer != NULL && prompt->buffer[0] != '\0'
		&& is_tab(prompt->buffer) != -1 && check_chev(prompt->buffer) != -1)
	{
		if (data_to_lst(&pars, prompt->buffer) == -1)
		{
			free (prompt->buffer);
			free (prompt->user);
			return (1);
		}
	}
	tmp = pars;
	lst_to_tab(tmp, head);
	init_pipe_cmd(head, pars, prompt);
	free_prompt(pars, prompt);
	return (0);
}

void	exit_ctrld(t_prompt *prompt, t_pars *pars)
{
	if (!prompt->buffer)
	{
		printf("exit\n");
		free_prompt(pars, prompt);
		exit (1);
	}
}
