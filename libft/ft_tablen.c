/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:54:09 by aboymond          #+#    #+#             */
/*   Updated: 2022/09/30 17:54:25 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int        ft_tablen(char **tab)
{
    int i;

    i = 0;
    if (tab == NULL)
        return (0);
    while (tab[i] != NULL)
        i++;
    return (i);
}