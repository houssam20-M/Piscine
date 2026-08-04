#include <unistd.h>

void ft_putnbr(int nb)
{
    long int i;
    char c;

    i = nb;
    if(i < 0)
    {
        write(1, "-", 1);
        i = -i;
    }
    if(i >= 10)
    {
        ft_putnbr(i/10);
    }
    c = '0' + i % 10;
    write(1, &c, 1);
}

int main()
{
    ft_putnbr(-42);
    return (0);
}
