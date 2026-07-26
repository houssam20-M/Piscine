#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i = 0;
    unsigned int x = ft_strlen(src);

    if(size != 0)
    {
        while(src[i] != '\0' && i < size -1)
        {
            dest[i] = src[i];
            i++;
        }
        return (x);
    }
}

int main()
{
    char src[] = "Hello";
    char dest[] = "World!";

    printf("%d\n%s\n", ft_strlcpy(dest, src, 10), dest);
}
