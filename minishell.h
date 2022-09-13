/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:46:29 by piow00            #+#    #+#             */
/*   Updated: 2022/09/13 18:31:18 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

// struct list chained

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

// typedef struct s_envi
// {
// 	char **
// }

int		prompt(char **envp);
char	*path(void);
char	*username(char **envp);

// Env

char	**env_cpy(char **envp);

// list chained

t_node	*empty_lst(void);
int		isempty(t_node *L);
t_node	*create_cell(int data);
t_node	*add_list(t_node *L, int data, int pos);

#endif