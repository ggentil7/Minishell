
#include "../minishell.h"

int	bultin_env(t_pars *pars, t_node *env)
{
	t_node	*tmp;

	tmp = env;
	if (pars->args[1] == NULL)
	{
		print_env(tmp);
	}
	else
	{
		printf("env: %s: No such file or directory\n", pars->args[1]);
		return (127);
	}
	return (0);
}

int	bultin_unset(t_pars *pars, t_node *env)
{
	int	i;

	i = 1;
	if (pars->args[1] == NULL)
	{
		printf("unset: not enough arguments\n");
		return (1);
	}
	else
	{
		while (pars->args[i])
		{
			lstclear_cell(env, pars->args[i]);
			i++;
		}
	}
	return (0);
}

int	bultin_export(t_pars *pars, t_node *node)
{
	t_node	*env;
	char 	*tmp;
  	int		i;
  
	i = 0;
	env = node;
	if (pars->args[1] == NULL)
	{
		env->args = env_to_tab(env);
		env->args = env_sort(env->args);
		print_export(env->args);
	}
	else
	{
		i = 0;
		while (pars->args[++i])
		{
			tmp = check_equal_env(pars->args[i]);

			if (search_env_var(node, tmp) != NULL )
			{
				if (ft_strchr(pars->args[i], '=') != NULL)
				{
					del_env(node, tmp);

					add_to_export_lst(pars, env, pars->args[i]);
				}
			}
			else
				add_to_export_lst(pars, env, pars->args[i]);
			free (tmp);
		}

	}
	return (0);
}
