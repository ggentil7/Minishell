#include "../minishell.h"

int	is_quote(char *data, int i)
{
	if (data[i] == '\'')
	{
		i++;
		//printf("i = %d\n", i);
		i = is_s_quote(data, i);
		//printf(" normalement -1 mais i = %d\n", i);
		if (i == -1)
			return (-1);
	}
	//usleep(200);
	if (data[i] == '\"')
	{
		i++;
		i = is_d_quote(data, i);
		//printf("i 2 = %d\n", i);
		if (i == -1)
			return (-1);
	}
	return (i);
}

int	is_s_quote(char *data, int i)
{
	//printf("i s_q = %d\n", i);
	while (data[i] != '\'')
	{
		//printf("ou la data[%c], i = [%d]\n", data[i], i);
		if (data[i] == '\0')
		{
			printf("Error [\']!\n");
			return (-1);
		}
		i++;
	}
	return (i);
}

int	is_d_quote(char *data, int i)
{
	while (data[i] != '\"')
	{
		//printf("data[%c], i = %d\n", data[i], i);
		if (data[i] == '\0')
		{
			printf("Error [\"] !\n");
			return (-1);
		}
		i++;
	}
	return (i);
}

// int	check_s_q(char *line)
// {
// 	int	i;
// 	int	compt;

// 	i = -1;
// 	compt = 0;
// 	while (line[++i])
// 	{
// 		printf("avant line s_q [%c], i = %d\n", line[i], i);
// 		if (line[i] == 39)
// 		{
// 			compt++;
// 			i = is_quote(line, i);
// 			i--;
// 		}
// 		printf("line s_q [%c], i = %d\n", line[i], i);
// 		printf("compt s_q = %d\n", compt);
// 	}
// 	if (compt % 2 == 1)
// 		return (1);
// 	return (0);
// }

// int	check_d_q(char *line)
// {
// 	int	i;
// 	int	compt;

// 	i = 0;
// 	compt = 0;
// 	while (line[i])
// 	{
// 		printf("avant line d_q [%c], i = %d\n", line[i], i);
// 		if (line[i] == 34)
// 		{
// 			compt++;
// 			i = is_quote(line, i);
// 			i--;
// 		}
// 		printf("line d_q [%c], i = %d\n", line[i], i);
// 		printf("compt d_q = %d\n", compt);
// 		i++;
// 	}
// 	if (compt % 2 == 1)
// 		return (1);
// 	return (0);
// }
