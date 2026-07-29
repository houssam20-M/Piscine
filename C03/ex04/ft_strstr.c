#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    if(to_find[0] == '\0')
    {
        return (str);
    }
    while (str[i] != '\0')
    {
        j = 0;
        while (str[i+j] == to_find[j] && to_find[j] != '\0')
        {
            j++;
        }
        if (to_find[j] == '\0')
        {
            return (&str[i]);
        }
        i++;
    }
    return (0);
}

int main()
{
    char *result;
    char str[] = "Hello World";
    char to_find[] = "World";

    result = ft_strstr(str, to_find);
    if (result)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("0\n");
    }
}
