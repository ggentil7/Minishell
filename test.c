#include "minishell.h"
#include <string.h>

char **sort(char **tab);

int main (void)
{
	char **tab;
	char **tab2;
	int i = 0;

	tab = calloc(sizeof(char *), (8 + 1));
	tab[0] = "c";
	tab[1] = "D";
	tab[2] = "a";
	tab[3] = "h";
	tab[4] = "i";
	tab[5] = "A";
	tab[6] = "k";
	tab[7] = "e";
	sort(tab);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}

char **sort(char **tab)
{
	int i;
	int j;
	int n;
	char *tmp;

	i = 0;
	j = 0;
	n = 8;
	while (j < n)
	{
		i = j + 1;
		while (i < n)
		{
			if (strcmp(tab[j], tab[i]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			i++;
		}
		j++;
	}
	return (tab);
}