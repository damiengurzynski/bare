#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
            i++;
            j = 0;
        }
        else
        {
            dir[i][j] = c;
            j++;
        }
    }
    fclose(file);
    system("rm tmp");
}

int     main(void)
{
    char    *co_inv;
    char    *co_def;
    char    dir[20][20];
    
    co_inv = "\e[7m";
    co_def = "\e[27m";
//    printf("%sWENK%s\n", co_inv, co_def);
    ft_getdir(dir);
    printf("%c\n", dir[2][0]);
    return (0);
}
