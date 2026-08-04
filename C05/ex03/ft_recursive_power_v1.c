#include <stdio.h>

long long ft_recursive_power(int nb, int power)
{
    if(power < 0)
    {
        return (0);
    }
    else if(power == 0)
    {
        return (1);
    }
    return(nb * ft_recursive_power(nb, power -1));
}

int main()
{
    printf("9^15 =  %lld\n", ft_recursive_power(9, 15));
}
