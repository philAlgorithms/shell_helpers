#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t parent;

    parent = getppid();
    printf("%u\n", parent);

    return(0);
}