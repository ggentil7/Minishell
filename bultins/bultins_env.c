
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
	char 	*tmp2;
  	int		i;
	// FILE		*file;
  
	i = 0;
	env = node;
	// file = fopen(tmp2, "txt");
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
			tmp2 = check_equal_env(pars->args[i]);
			// fprintf(file, "\033[0;31mexport tmp2 = [%s]  [%p]\033[0m\n", tmp2, tmp2);
			// fprintf(file, "---------------------------------------------------------\n");
			// fprintf(file, "tmp2 %s\n", tmp2);
			if (search_env_var(node, tmp2) != NULL )
			{
				// printf("TEEEEST\n");
				if (ft_strchr(pars->args[i], '=') != NULL)
				{
					del_env(node, tmp2);
					// free (tmp2);
					// fprintf(file, "export 2 tmp2 = [%s]  [%p], tmp3 = [%s]  [%p]\n", tmp2, tmp2, tmp3, tmp3);
					// fprintf(file, "---------------------------------------------------------\n");
					add_to_export_lst(pars, env, pars->args[i]);
				}
			}
			else
				add_to_export_lst(pars, env, pars->args[i]);
			free (tmp2);
		}

	}
	// if (tmp2 != NULL)
	// 	free (tmp2);
	return (0);
}
