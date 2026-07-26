#include <stdio.h>
#include <string.h>

char *ft_strlowcase(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}

char *ft_strcapitalize(char *str)
{
    int i = 0;
    int j = 1;

    ft_strlowcase(str);
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            if(j == 1)
            {
                str[i] = str[i] - 32;
                j = 0;
            }
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            j = 0;
        }
        else
        {
            j = 1;
        }
        i++;
    }
    return (str);
}

int main()
{
    char str[] = "hi, how are you? 42words forty-two; fifty+and+one";
    
    ft_strcapitalize(str);
    printf("%s\n", ft_strcapitalize(str));
}
