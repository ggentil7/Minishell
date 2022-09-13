/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:46:29 by piow00            #+#    #+#             */
/*   Updated: 2022/09/13 16:08:15 by aboymond         ###   ########.fr       */
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

typedef struct cell_t
{
    int data;
    struct cell_t *next;
}list,cell;

int	prompt(char **envp);
char *path(void);

// list chained

list *empty_lst();
int isempty(list *L);
cell *create_cell(int data);
list *add_list(list *L, int data, int pos);

#endif