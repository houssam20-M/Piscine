#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i] == s2[i])
    {
        if (s1[i] == '\0')
        {
            return (0);
        }
        i++;
    }
    return (s1[i] - s2[i]);
}
int main()
{
    char s1[] = "housSaM";
    char s2[] = "HoussaM";

    printf("%d\n", ft_strcmp(s1, s2));
}
