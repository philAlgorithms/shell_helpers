#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    int i;

    for (i=0; i < strlen(av[0]) - 3; i++)
    {
        printf("%s\n", av[i]);
    }
}