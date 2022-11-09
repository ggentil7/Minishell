/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:22:45 by ggentil           #+#    #+#             */
/*   Updated: 2022/11/09 19:22:46 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	ret(char *msg, int ret, int num)
{
	g_ret = ret;
	if (num == 0)
	{
		if (msg != NULL)
			printf("%s\n", msg);
	}
	if (num == 1)
	{
		if (msg != NULL)
			printf("minishell: %s: command not found\n", msg);
	}
	return (0);
}
