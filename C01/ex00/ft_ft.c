#include <stdio.h>

void    ft_ft(int *nbr)
{
    *nbr = 42;
}

int main()
{
    int a;
    int *p;

    p = &a;
    ft_ft(p);
    printf("%d\n", a);
    return (0);
}