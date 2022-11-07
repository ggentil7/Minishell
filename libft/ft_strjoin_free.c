
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*strnew;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	strnew = ft_calloc(sizeof(*strnew), (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (strnew && s1[i])
	{
		strnew[i] = s1[i];
		i++;
	}
	while (strnew && s2[j])
	{
		strnew[i] = s2[j];
		j++;
		i++;
	}
	free(s1);
	free(s2);
	return (strnew);
}