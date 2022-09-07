/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:26:37 by piow00            #+#    #+#             */
/*   Updated: 2022/09/07 12:19:36 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

int main()
{
	char *buffer = readline("> ");
	if (buffer)
	{
		printf("You entered: %s\n", buffer);
		free(buffer);
	}
	return 0;
}