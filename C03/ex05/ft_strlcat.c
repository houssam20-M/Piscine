#include <stdio.h>

unsigned int ft_strlen(char *str)
{
    unsigned int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int d_len;
    unsigned int s_len;
    unsigned int i;

    d_len = ft_strlen(dest);
    s_len = ft_strlen(src);
    i = 0;
    if (size <= d_len)
    {
        return (size + s_len);
    }
    while (src[i] && (d_len + i) < (size -1))
    {
        dest[d_len + i] = src[i];
        i++;
    }
    dest[d_len + i] = '\0';
    return (d_len + s_len);
}
int main()
{
    char dest[20] = "Hello ";
    char src[] = "Houssam";
    printf("%d\n", ft_strlcat(dest, src, 20));
    printf("%s\n", dest);
}
