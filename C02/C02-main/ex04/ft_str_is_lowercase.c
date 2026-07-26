#include <stdio.h>
#include <string.h>

int     ft_str_is_lowercase(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(!(str[i] >= 'a' && str[i] <= 'z'))
        {
            return(0);
        }
        i++;
    }
    return(1);
}

int main()
{
    char str[] = "AbsdGFs"; 

    ft_str_is_lowercase(str);
    printf("%d\n", ft_str_is_lowercase(str));
}



