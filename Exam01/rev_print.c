#include <unistd.h>

char	*ft_rev_print(char *str)
{
	int i = 0;
	int end;
	char temp;

	while(str[i] != '\0')
	{
		i++;
	}
	end = i -1;
	while (end >= 0)
	{
		write(1, &str[end], 1);
		end--;
	}
	write(1, "\n", 1);
	return (str);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_rev_print(argv[1]);
	return (0);
}
