#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/*
char	*get_next_line(int fd)
{

}
*/

int		main(int argc, char **argv)
{
	int		argv_counter;
	//int		argv_index;
	ssize_t	*fildes;
	int		fildes_counter;

	argv_counter = 1;
	//argv_index = 0;
	fildes = NULL;
	fildes_counter = 0;
	if (argc < 2)
	{
		printf("\n\tNo se ha proporcionado mingun argumento\n\n");
	}
	else
	{
		fildes = malloc((argc - 1) * sizeof(ssize_t));
		printf("\n\tEl numero de argumentos es: %i\n\n", argc - 1);
		while (argv_counter < (argc))
		{
			fildes[fildes_counter] = open(argv[argv_counter], O_RDONLY);
			printf("\tEl argumento %d es: %s\n", argv_counter, argv[argv_counter]);
			printf("\tEl FD del argumento %d es: %zd\n\n", argv_counter, fildes[fildes_counter]);
			//fildes[fildes_counter] = close(argv_counter);
			argv_counter++;
			fildes_counter++;
		}
		/*while (fildes_counter > 1)
		{
			printf("\tVoy a cerrar el FD %d:\n", fildes_counter);
			fildes[fildes_counter] = close(fildes_counter);
			fildes_counter--;
		}*/
		printf("\n\tEl numero de argumentos es: %i\n\n", argc - 1);
		printf("\n\tEl fildes_counter es: %i\n\n", fildes_counter);
		printf("\n\tEl argv_counter es: %i\n\n", argv_counter);
		/*argv_counter = 1;
		while (argv_counter < (argc))
		{
			printf("\tEl argumento %d es: %s\n", argv_counter, argv[argv_counter]);
			printf("\tEl FD del argumento %d es: %zd\n\n", argv_counter, fildes[fildes_counter]);
			//fildes[fildes_counter] = close(argv_counter);
			argv_counter++;
			fildes_counter++;
		}*/
		printf("\n");
	}
	return (0);
}
