
#include "minishell.h"

void    tk_data(t_pars **pars, char *data)
{
    int     i;
    int     j;
   // t_pars  *tmp;
    char   *temp;

    i = -1;
    j = 0;
   // tmp = pars;
    temp = NULL;
    while (++i < ft_istrlen(data) + 1)
    {
        printf("i = %d, j = %d\n", i, j);
        if (i == ft_istrlen(data))
        {
            temp = ft_substr(data, j, i);
            printf("temp data = %s\n", temp);
            *pars = p_add_list(*pars, temp);
        }
        else if (data[i] == ' ')
        {
            temp = ft_substr(data, j, i);
            printf("temp = %s\n", temp);
            *pars = p_add_list(*pars, temp);
            j = i + 1;
        }
        temp = NULL;
    }
}