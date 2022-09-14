/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:26:37 by piow00            #+#    #+#             */
/*   Updated: 2022/09/14 14:41:10 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;

	node = NULL;
	(void)argc;
	(void)argv;
	env_cpy(&node, envp);
	while (1)
		prompt(node); // copie de la liste 
	return (0);
}
