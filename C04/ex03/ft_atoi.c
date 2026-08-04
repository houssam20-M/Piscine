#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int s;
    int r;

    i = 0;
    s = 1;
    while(str[i] && (str[i] >= 9 || str[i] <= 13) && str[i] == 32)
    {
        i++;
    }
    while(str[i] && (str[i] == 43 || str[i] == 45))
    {
        if(str[i] == 45)
        {
            s *= -1;
        }
        i++;
    }
    r = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + str[i] - '0';
        i++;
    }
    return (r * s);
}

int main(void)
{
    printf("%d\n", ft_atoi("---+--+1234ab567"));
    return (0);
}
