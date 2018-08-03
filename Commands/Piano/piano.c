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

    dir[0][0] = '.';
    dir[0][1] = '.';
    dir[0][2] = '/';
    dir[0][3] = '\0';
    i = 1;
    j = 0;
    system("ls -p > .tmp");
    file = fopen(".tmp", "r");
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
    system("rm .tmp");
}

int     ft_dirlen(char dir[20][20])
{
    int     i;

    i = 0;
    while (dir[i][0] != 0)
        i++;
    return (i - 1);
}

int     main(void)
{
    char    dir[20][20];
    int     i;
    int     c;
    int     last;
    int     cur;
    int     dirlen;
    char    *curdir;
   
    i = 0;
    c = 0;
    last = 0;
    cur = 0;
    ft_getdir(dir);
    dirlen = ft_dirlen(dir);
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
    system("stty cbreak");
    i = 0;
    while (c != 27)
    {
        c = getchar();
        if (c == 32)
        {
            chdir(dir[cur]);
            ft_getdir(dir);
            dirlen = ft_dirlen(dir);
            last = 49;
            c = 49;
            cur = 0;
            system("clear");
        }
        else if (c > last && cur == dirlen)
            cur = 0;   
        else if (c < last && cur == 0)
            cur = dirlen;
        else if (c > last)
            cur++;
        else if (c == last)
            cur = cur;
        else
            cur--;
        system("clear");
        last = c;
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







