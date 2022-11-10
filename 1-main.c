#include "main.h"

int main(void)
{
    char **words;
    char *line = "This is a goal";
    char *delim = "-";
    int i;

    words = _strtok(line, delim);

    for (i= 0; i < (int)sizeof(words); i++)
    {
        printf("%s\n", words[i]);
    }

    return (0);
}