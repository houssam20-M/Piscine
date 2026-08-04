#include <stdio.h>

int ft_recursion_power(int nb, int power)
{
    if(power < 0)
    {
        return (0);
    }
    else if(power == 0)
    {
        return (1);
    }
    return (nb * ft_recursion_power(nb, power - 1));
}

int main()
{
    printf("%d\n", ft_recursion_power(2, 4));
}
