
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <termios.h>
# include "./libft/libft.h"

// struct list chained

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
	char			**args;
}	t_node;

typedef struct s_pars
{
	char			*p_data;
	struct s_pars	*next;
	char			**args;
	char			*cmd;
	int				chevr;
	int				doll_flag;
	char			*doll_tab;
	pid_t			pid;
	int				fd_in;
	int				fd_out;
}	t_pars;

typedef struct s_prompt
{
	char			*buffer;
	char			*user;
}	t_prompt;

int		g_ret;

char	*check_equal_env(char *str);
int		check_env_var(char *env, char *vari);

// Prompt
int		prompt_(t_node *node, t_pars *pars, t_prompt *prompt);
char	*path(void);								/* recupere le path */
char	*username(t_node *head);					/* user pour prompt */
void	print_prompt(t_pars *pars);					/* affiche le prompt */
int		is_space(char *data);

// Init
int		init_cmd(t_pars *pars);
void	init_pipe(t_pars *pars);

// Utils Bultins
char	**env_sort(char **env);
char	**env_to_tab(t_node *node);
t_node	*add_to_export_lst(t_pars *pars, t_node *node, char *args);
char	**add_to_export_tab(t_pars *pars);
char	**tabjoin(char **tab, char **args);

// Bultins print
int		print_export(char **env);
int		print_export2(char **env, int i);
int		print_env(t_node *env);

// Error
int		error_quote(void);

// Parsing
int		check_data_to_lst(char *data);
int		data_to_lst(t_pars **pars, char *data);		/* prend les donnees de la ligne de cmd */
void	is_pipe(t_pars **pars, char *data, int i, int j);
void	is_zero(t_pars **pars, char *data, int i, int j);
int		is_space_pipe(char *data, int i);
int		is_double_pipe(char *data, int i);
int		check_pipe(char *data);
int		is_bs_pipe(char *data, int i);
int		is_tab(char *data);

// Parsing L2

int		lst_to_tab(t_pars *pars, t_node *node);

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
void	p_lstclear(t_pars *lst);
void	p_lstdelone(t_pars *lst);

// Env
void	env_cpy(t_node **node, char **envp);
int		check_env(char *env, char *vari);
char	*search_env(t_node *head, char *search);
char	*reste(char *str);
char	*check_equal(char *str);
char	*del_env(t_node *head, char *search);
char	*search_env_var(t_node *head, char *search);

// list chained
t_node	*empty_lst(void);
int		isempty(t_node *L);
t_node	*create_cell(char *data);
t_node	*add_list(t_node *L, char *data);
char	*getat(t_node *L, int pos);
void	lstdelone(t_node *lst);
void	lstclear(t_node *lst);
t_node	*lstclear_cell(t_node *node, char *data);

// Utils
char	**ft_split_pipe(char *s, char c, t_pars *pars, t_node *node);
char	**ft_split_quote(char *s, char c);
char	**split_to_remove(char **tab, t_pars *pars, t_node *node);
int		compte_quote(char *data);
int		*init_tab_compt_quote(char *data);
char	*is_dollars(char *tab, t_node *node);
char	*remove_dollars(char *tab);
int		ft_set(char *s, char c);
int		check_chev(char *chevr);
int		compt_doll(char *tab);
int		is_dollars_or_quote(char *line, int i);
char	*join_dollars(t_node *env, char *line, char *tmp, int i);
char	*after_egal(t_node *env, char *search);

// Free
void	free_tab(char **tab);
void	free_lst_pars(t_pars *pars);
void	free_lst_node(t_node *node);
void	free_prompt(t_pars *pars, t_prompt *prompt);

// Signal
void	handle_sigint(int sig);
void	handle_signal(struct termios *saved);
void	hide_key(struct termios *saved);
void	rl_replace_line(const char *text, int clear_undo);
void	rl_clear_history(void);
void	handle_sigquit(int sig);

// Bultins
int		bultin_search(t_pars *pars, t_node *env, t_prompt *prompt);
int		cmd(t_pars *pars, t_node *env, t_prompt *prompt);
int		bultin_echo_n(t_pars *pars, t_node *env);
int		bultin_echo(t_pars *pars, int i, t_node *env);
int		bultin_pwd(t_pars *pars);
int		bultin_cd(t_pars *pars, t_node *env);
int		bultin_env(t_pars *pars, t_node *env);
int		bultin_export(t_pars *pars, t_node *node);
int		bultin_unset(t_pars *pars, t_node *env);
int		is_bultin(t_pars *pars);
int		compt_egal(char *str);
int		bultin_export_la_suite(t_pars *pars, t_node *node);

// Bultouts
char	**conv_path(t_pars *pars, t_node *env);
int		exec_bultout_2(t_pars *pars, char **path_tab, char **env);
void	execution(t_pars *pars, t_node *env);
int		if_path_not_exist(t_pars *pars, char **path_tab, char **env);

// Init
int		init_cmd(t_pars *pars);

// Pipe
int		pipeline(t_pars *pars, t_node *env, t_prompt *prompt);
void	free_pipe(t_pars *pars);
void	wait_pipe(t_pars *pars);

// Redirection
int		redirection_tab(t_pars *pars);
int		chevron_detect(t_pars *pars, char *tab, int i);
int		del_chevron_more(t_pars *pars,  int i);

// Chevrons
int		chevron_d_simple(t_pars *pars, int i);
int		chevron_d_double(t_pars *pars, int i);
int		chevron_g_simple(t_pars *pars, int i);
int		chevron_g_double(t_pars *pars, int i);

// Return
int	ret(char *msg, int ret, int num);

// Exit
int		exit_minishell(t_pars *pars, t_node *env, t_prompt *prompt);

#endif