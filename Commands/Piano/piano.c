#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char    *ft_col(int i)
{
    char    *inv;
    char    *def;
    
    inv = "\e[7m";
    def = "\e[27m";
    if (i == 1)
        return (inv);
    else
        return (def);
}

void    ft_getdir(char dir[20][20])
{
    FILE    *file;
    int     c;
    int     i;
    int     j;

    i = 0;
    j = 0;
    system("ls > tmp");
    file = fopen("tmp", "r");
    while ((c = getc(file)) != EOF)
    {
        if (c == '\n')
        {
            dir[i][j] = '\0';
            i++;
            j = 0;
        }
        else
        {
            dir[i][j] = c;
            j++;
        }
    }
    dir[i][j] = 0;
    fclose(file);
    system("rm tmp");
}

int     main(void)
{
    char    dir[20][20];
    int     i;
    int     c;
    int     cur;
   
    i = 0;
    c = 0;
    cur = 0;
    ft_getdir(dir);
    system("clear");
    while (dir[i][0] != 0)
    {
        if (i == cur)
        {
            printf("%s%s%s\n", ft_col(1), dir[i], ft_col(0));
            i++;
        }
        else
        {
            printf("%s\n", dir[i]);
            i++;
        }
    }
    i = 0;
    while (1)
    {
        c = getchar();
        system("clear");
        printf("c = %d", c);
        if (c > cur)
            cur++;
        else
            cur--;
        while (dir[i][0] != 0)
        {
            if (i == cur)
            {
                printf("%s%s%s\n", ft_col(1), dir[i], ft_col(0));
                i++;
            }
            else
            {
                printf("%s\n", dir[i]);
                i++;
            }
        }
        i = 0;
    }
}







