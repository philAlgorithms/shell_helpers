#include "main.h"

int _strlen(char *s)
{
    size_t len = 0;

    while (*s++)
        len++;

    return (len);
}

int tok_size(char *str, char *delim)
{
    int size = 0, i = 0;

    while (str[i] != *delim && str[i] != '\0')
    {
        size++;
        i++;
    }
    return (size);
}

int tok_count(char *str, char *delim)
{
    int i, num = 0, len = 0;

    len = _strlen(str);

    for (i = 0; i < len; i++)
    {
        if (*(str + i) != *delim)
        {
            num++;
            i += tok_size(str + i, delim);
        }
    }

    return (num);
}

char **_strtok(char *line, char *delim)
{
    char **tokens;
    int i = 0, num, n, token_length, l;

    num = tok_count(line, delim);
    if (num == 0)
        return (NULL);

    tokens = malloc(sizeof(char *) * (num + 2));
    if(!tokens)
        return(NULL);

    for (n = 0; n < num; n++)
    {
        while (line[i] == *delim)
            i++;
        
        token_length = tok_size(line + i, delim);

        tokens[n] = malloc(sizeof(char) * (token_length + 1));
        if(!tokens[n])
        {
            for (i -= 1; i >= 0; i--)
                free(tokens[i]);
            free(tokens);
            return (NULL);
        }

        for (l = 0; l < token_length; l++)
        {
            tokens[n][l] = line[i];
            i++;
        }
        tokens[n][l] = '\0';
    }

    tokens[n] = NULL;
    tokens[n + 1] = NULL;

    return (tokens);
}

int main(void)
{
    char **tokens;
    char *line = "This-is-a-goal";
    char *delim = "-";
    int i;

    tokens = _strtok(line, delim);
// printf("%s", tokens[10]);
   for ( i = 0; tokens[i]; i++)
   {
    printf("%s\n", tokens[i]);
   }
    return (0);
}