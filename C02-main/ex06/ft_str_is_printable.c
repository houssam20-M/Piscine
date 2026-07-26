#include <stdio.h>
#include <string.h>

int ft_str_is_printable(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(!(str[i] >= 32 && str[i] <= 126))
        {
            return(0);
        }
        i++;
    }
    return (1);
}

int main()
{
    char str[] = "Hello!\n";

    ft_str_is_printable(str);
    printf("%d\n", ft_str_is_printable(str));
}
