
#include "minishell.h"

char	conv_to_char(int i, char **conv)
{
	int		j;
	char	*tmp;

	j = 0;
	while (conv[j][i])
	{
		tmp = ft_strjoin(tmp, conv[j]);
		printf("%s\n", tmp);
		j++;
	}
	return (*tmp);
}
