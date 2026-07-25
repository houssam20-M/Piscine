#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 10;
    int y = 20;

    printf("%d\n", x);
    printf("%d\n", y);

    ft_swap(&x, &y);

    printf("--------------\n");

    printf("%d\n", x);
    printf("%d\n", y);
}