#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int result;

    if(nb < 0)
    {
        return (0);
    }
    result = 1;
    while (nb > 0)
    {
        result *= nb;
        nb--;
    }
}

int main()
{
    printf("%d\n", ft_iterative_factorial(5));
}
