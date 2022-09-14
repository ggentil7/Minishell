/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:26:37 by piow00            #+#    #+#             */
/*   Updated: 2022/09/14 16:45:36 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	
	(void)argc;
	(void)argv;
	node = NULL;
	env_cpy(&node, envp);
	while (1)
		prompt(node); // copie de la liste 
	return (0);
}
 