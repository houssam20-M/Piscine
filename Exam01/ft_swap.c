#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 7;
	int y = 8;

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	ft_swap(&x, &y);

	printf("x = %d\n", x);
	printf("y = %d\n", y);
}
