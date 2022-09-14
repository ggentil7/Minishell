/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:46:29 by piow00            #+#    #+#             */
/*   Updated: 2022/09/14 14:20:07 by aboymond         ###   ########.fr       */
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
	char			*data;
	struct s_node	*next;
}	t_node;

typedef struct s_envi
{
	char	**envi;
}	t_envi;

int		prompt(t_node *node);
char	*path(void);
char	*username(char **envp);

// Conv

char	conv_to_char(int i, char **conv);

// Env

void	env_cpy(/*t_envi *envi,*/ t_node **node, char **envp);
char	*getat(t_node *L, int pos);

// list chained

t_node	*empty_lst(void);
int		isempty(t_node *L);
t_node	*create_cell(char *data);
t_node	*add_list(t_node *L, char *data/*, int pos*/);


#endif