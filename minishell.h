
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
char	*path(void);								/* recupere le path */
char	*username(t_node *head);						/* user pour prompt */

// Conv

//char	conv_to_char(int i, char **conv);

// Env

void	env_cpy(t_node **node, char **envp);		/* copie envp dans liste chainee */
int		check_env(char *env, char *vari);			/* compare variable d'env */
char	*search_env(t_node *head, char *search);	/* cherche la variable d'env */
char	*reste(char *str);

// list chained

t_node	*empty_lst(void);
int		isempty(t_node *L);
t_node	*create_cell(char *data);
t_node	*add_list(t_node *L, char *data);
char	*getat(t_node *L, int pos);

#endif