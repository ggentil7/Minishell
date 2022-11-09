/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:00:02 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:53:02 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Prompt
int		prompt_(t_node *node, t_pars *pars, t_prompt *prompt);
char	*path(void);
void	exit_ctrld(t_prompt *prompt, t_pars *pars);
char	*username(t_node *head);
char	*username2(t_node *head, char *at, char *mini, char *dol);

// Init
int		init_cmd(t_pars *pars);
void	init_pipe(t_pars *pars);

// Bultins utils
char	**env_sort(char **env);
char	**env_to_tab(t_node *node);
t_node	*add_to_export_lst(t_pars *pars, t_node *node, char *args);

// Bultins print
int		print_export(char **env);
int		print_export2(char **env, int i);
int		print_env(t_node *env);

// Error
int		error_quote(void);

// Parsing
int		data_to_lst(t_pars **pars, char *data);
int		check_data_to_lst(char *data);
void	is_zero(t_pars **pars, char *data, int i, int j);
int		is_space(char *data);
int		is_tab(char *data);

// Parsing pipe
int		check_pipe(char *data);
void	is_pipe(t_pars **pars, char *data, int i, int j);
int		is_double_pipe(char *data, int i);
int		is_bs_pipe(char *data, int i);
int		is_space_pipe(char *data, int i);

// Parsing L2
int		lst_to_tab(t_pars *pars, t_node *node);

// Check quote
char	*remove_quote(char *data);
int		is_quote(char *data, int i);
int		is_s_quote(char *data, int i);
int		is_d_quote(char *data, int i);
int		after_is_quote(char *data, int i);

// Lst clear
void	p_lstclear(t_pars *lst);
void	p_lstdelone(t_pars *lst);
void	lstclear(t_node *lst);
void	lstdelone(t_node *lst);
t_node	*lstclear_cell(t_node *node, char *data);

// Lst utils
t_node	*lstclear_cell2(t_node *supp, t_node *node, t_node *prec, char *data);

// Env
void	env_cpy(t_node **node, char **envp);
char	*search_env_var(t_node *head, char *search);
char	*search_env(t_node *head, char *search);
char	*del_env(t_node *head, char *search);
int		check_env(char *env, char *vari);

// Env utils
char	*after_egal(t_node *env, char *search);
char	*reste(char *str);
int		check_env_var(char *env, char *vari);

// lst parsing
t_pars	*p_add_list(t_pars *L, char *data);
t_pars	*p_create_cell(char *data);
t_pars	*p_empty_lst(void);
char	*p_getat(t_pars *L, int pos);
int		p_isempty(t_pars *L);

// Env lst chaine
t_node	*empty_lst(void);
t_node	*create_cell(char *data);
t_node	*add_list(t_node *L, char *data);
int		isempty(t_node *L);
char	*getat(t_node *L, int pos);

// Utils
int		*init_tab_compt_quote(char *data);
int		compte_quote(char *data);
int		ft_set(char *s, char c);
char	**ft_split_pipe(char *s, char c, t_pars *pars, t_node *node);
char	**split_to_remove(char **tab, t_pars *pars, t_node *node);

// Utils 2
char	*check_equal(char *str);
char	*check_equal_env(char *str);
int		check_chev(char *chevr);
void	init_pipe_cmd(t_node *head, t_pars *pars, t_prompt *prompt);
int		while_chevron(char *line, char *key, int fd[1]);

// Utils Dollars
char	*is_dollars(char *tab, t_node *node);
int		is_dollars_or_quote(char *line, int i);
char	*join_dollars(t_node *env, char *line, char *tmp, int i);
char	*join_dollars_la_suite(char *line, char *tmp, int i, int j);

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
int		bultin_cd(t_pars *pars, t_node *env);
int		bultin_echo(t_pars *pars, int i, t_node *env);
int		bultin_echo_n(t_pars *pars, t_node *env);
int		bultin_pwd(t_pars *pars);
int		bultin_env(t_pars *pars, t_node *env);
int		bultin_unset(t_pars *pars, t_node *env);
int		bultin_search(t_pars *pars, t_node *env, t_prompt *prompt);
int		bultin_export(t_pars *pars, t_node *node);
int		cmd(t_pars *pars, t_node *env, t_prompt *prompt);
void	execution(t_pars *pars, t_node *env);
int		is_bultin(t_pars *pars);
int		bultin_export_la_suite(t_pars *pars, t_node *node);

// Bultouts
char	**conv_path(t_pars *pars, t_node *env);
int		exec_bultout_2(t_pars *pars, char **path_tab, char **env);
int		if_path_not_exist(t_pars *pars, char **path_tab, char **env);
int		return1(int i);

// Pipe
int		pipeline(t_pars *pars, t_node *env, t_prompt *prompt);
void	free_pipe(t_pars *pars);
void	wait_pipe(t_pars *pars);

// Redirection
int		redirection_tab(t_pars *pars);
int		chevron_detect(t_pars *pars, char *tab, int i);
int		del_chevron_more(t_pars *pars, int i);

// Chevrons
int		chevron_d_simple(t_pars *pars, int i);
int		chevron_d_double(t_pars *pars, int i);
int		chevron_g_simple(t_pars *pars, int i);
int		chevron_g_double(t_pars *pars, int i);
int		error_pipe(int fd[2]);

// Exit
int		exit_minishell(t_pars *pars, t_node *env, t_prompt *prompt);
int		ret(char *msg, int ret, int num);

#endif