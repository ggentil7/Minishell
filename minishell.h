
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
	char			**args;
	int				fd_in;
	int				fd_out;
}	t_pars;

int		prompt(t_node *node, t_pars *pars);
char	*path(void);								/* recupere le path */
char	*username(t_node *head);					/* user pour prompt */

// Parsing
int		check_data_to_lst(char *data);
int		data_to_lst(t_pars **pars, char *data);		/* prend les donnees de la ligne de cmd */
void	is_pipe(t_pars **pars, char *data, int i, int j);
void	is_zero(t_pars **pars, char *data, int i, int j);
int		is_space_pipe(char *data, int i);
int		is_double_pipe(char *data, int i);
int		check_pipe(char *data);
int		is_bs_pipe(char *data, int i);

// Parsing L2

int		lst_to_tab(t_pars *pars);

// Check quote
int		is_s_quote(char *data, int i);
int		is_d_quote(char *data, int i);
int		is_quote(char *data, int i);
int		check_s_q(char *line);
int		check_d_q(char *line);
int		after_is_quote(char *data, int i);
char	*remove_quote(char *data);

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

// Utils
char	**ft_split_pipe(char *s, char c);
char	**ft_split_quote(char *s, char c);
char	**split_to_remove(char **tab);
int		compte_quote(char *data);
int 	*init_tab_compt_quote(char *data);

// Signal
void	handle_sigint(int sig);

void	rl_replace_line(const char *text, int clear_undo);

void	rl_clear_history(void);

#endif