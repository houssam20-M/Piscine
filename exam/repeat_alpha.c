#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int repeat;

    if(argc != 2)
    {
        write(1, "\n", 1);
        return(0);
    }

    while(argv[1][i])
    {
        if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            repeat = argv[1][i] - 96;
            while(repeat>0)
            {
                write(1, &argv[1][i], 1);
                repeat --;
            }
        }
        else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            repeat = argv[1][i] - 64;
            while (repeat > 0)
            {
                write(1, &argv[1][i], 1);
                repeat--;
            }
        }
        else
        {
            write(1, &argv[1][i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}