
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

// struct list chained

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
}	t_node;

typedef struct s_pars
{
	char			*p_data;
	struct s_pars	*next;
}	t_pars;

int		prompt(t_node *node, t_pars *pars);
char	*path(void);								/* recupere le path */
char	*username(t_node *head);					/* user pour prompt */

// Parsing

void	data_to_lst(t_pars **pars, char *data);		/* prend les donnees de la ligne de cmd */

// List chained parsing

t_pars	*p_empty_lst(void);
t_pars	*p_create_cell(char *data);
t_pars	*p_add_list(t_pars *L, char *data);
int		p_isempty(t_pars *L);
char	*p_getat(t_pars *L, int pos);
void	p_lstclear(t_pars **lst, void (*del)(void *));
void	p_lstdelone(t_pars *lst, void (*del)(void *));

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

// Signal
void	handle_sigint(int sig);

void	rl_replace_line(const char *text, int clear_undo);


#endif