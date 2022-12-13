#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
/*
char	*get_next_line(int fd)
{

}
*/
int		main(int argc, char **argv)
{
	int		counter;
	ssize_t	*fildes;

	counter = 0;
	fildes = NULL;
	if (argc < 2)
	{
		printf("\n\tNo se ha proporcionado mingun argumento\n\n");
	}
	else
	{
		printf("\n\tEl numero de argumentos es: %i\n", argc - 1);
		while (counter < (argc - 1))
		{
			printf("\n\tEl argumento %d es: ", counter);
			while (*argv[counter] != '\0')
			{
				write(1, *argv, 1);
				argv++;
			}
			counter++;
		}
		/*while (counter < argc)
		{
			fildes[counter] = open(argv[counter + 1], O_RDONLY);
			if (fildes[counter] == -1)
				printf("\n\tError al abrir el archivo\n\n");
			else
				printf("\n\tEl File Descriptor es: %zu\n\n", fildes[counter]);
			counter++;
		}*/
	}
	return (0);
}
