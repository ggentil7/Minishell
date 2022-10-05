/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:51:54 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/06 00:49:17 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strncmp(const char *f, const char *s, size_t l)
// {
// 	unsigned int	i;

// 	i = 0;
// 	if (!l)
// 		return (0);
// 	while ((i < l - 1) && (f[i] && s[i]) && (f[i] == s[i]))
// 		i++;
// 	return ((unsigned char)f[i] - (unsigned char)s[i]);
// }

int	ft_strncmp(const char *f, const char *s, size_t l)
{
	unsigned int i;

	i = 0;
	while (f[i] != '\0' && s[i] != '\0' && i < l)
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
		++i;
	}
	if (i != l)
		return (f[i] - s[i]);
	return (0);
}