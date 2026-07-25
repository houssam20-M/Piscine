#include <unistd.h>

void first_word(char *str)
{
	int i = 0;

	while(str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
	}
	first_word(argv[1]);
	return (0);
}
