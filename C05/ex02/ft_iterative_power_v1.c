#include <stdio.h>

long long ft_iterative_power(int nb, int power)
{
    int i;
    long long j;

    i = 1;
    j = nb;

    if(power < 0)
    {
        return (0);
    }
    if(power == 0)
    {
        return (1);
    }
    while(i < power)
    {
        j = j * nb;
        i++;
    }
    return (j);
}

int main()
{
    printf("%lld\n", ft_iterative_power(9, 13));
    return (0);
}
