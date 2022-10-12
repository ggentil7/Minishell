#include "../minishell.h"

char	**conv_path(t_pars *pars, t_node *env)
{
	char	*path;
	char	**path_tab;
	int		i;
	int		y;

	(void)pars;
	i = 0;
	y = 0;
	path = search_env(env, "PATH");
	while (path[y] != '=')
	{
		if (path[y] == '\0')
			return (0);
		y++;
	}
	path_tab = ft_split(path, ':');
	path_tab[0] = ft_substr(path_tab[0], y + 1, (int)ft_strlen(path_tab[0]));
	while (path_tab[i])
	{
		y = 0;
		i++;
	}
	return (path_tab);
}
