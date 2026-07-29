#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(dest[i] != '\0')
    {
        i++;
    }
    while(src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
int main()
{
    char dest[20] = "Houssam ";
    char src[] = "Oubaha";

    printf("%s\n", ft_strcat(dest, src));
}
