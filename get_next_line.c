#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		n--;
		i++;
	}
	return (dst);
}

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)ptr)[i] = c;
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int 	total_spc;

	ptr = NULL;
	total_spc = nmemb * size;
	if (nmemb >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	ptr = malloc(total_spc);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_spc);
	return (ptr);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_next_line(ssize_t fd)
{
	static char	*buffer;
	char		string[1024];
	size_t		readed;
	int			i;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 0;
	printf("\t****%zd\n", fd);
	readed = read(fd, &buffer, BUFFER_SIZE);
	printf("\tLos caracteres leidos %zd\n\n\n", readed);
	//printf("%s", buffer);
	//ft_memcpy(string, buffer, 10);
	/*while (buffer[i] != '\0')
	{
		write(1, &buffer[i], 1);
		i++;
	}*/
	//string[i] = '\0';
	/*buffer[BUFFER_SIZE] = '\0';
	while (i < 10)
	{
		write(1, &buffer, 1);
		i++;
		buffer++;

	}*/
	return (buffer);
}

int		main(int argc, char **argv)
{
	ssize_t	*fildes;
	int		argv_counter;
	int		fildes_counter;
	//static char 	*buff;

	fildes = NULL;
	argv_counter = 1;
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
			printf("\tEl FD del argumento %d es: %zd\n", argv_counter, fildes[fildes_counter]);
			printf("\tEl fildes_counter es: %i\n", fildes_counter);
			printf("\tEl argv_counter es: %i\n\n\n", argv_counter);
			get_next_line(fildes[fildes_counter]);
			//printf("\t -- %s", buff);
			argv_counter++;
			fildes_counter++;
		}
		printf("\tEl fildes_counter es: %i\n", fildes_counter);
		printf("\tEl argv_counter es: %i\n\n", argv_counter);
		printf("\t------------------BIEN---------------------\n\n");
		/*while (fildes[fildes_counter - 1] != 0)
		{
			printf("\tVoy a cerrar el FD: %zd\n", fildes[fildes_counter - 1]);
			fildes[fildes_counter - 1] = close(fildes[fildes_counter - 1]);
			fildes_counter--;
			argv_counter--;
		}
		printf("\n");
		argv_counter = 1;
		while (argv_counter < (argc))
		{
			printf("\tEl argumento %d es: %s\n", argv_counter, argv[argv_counter]);
			printf("\tEl FD del argumento %d es: %zd\n", argv_counter, fildes[fildes_counter]);
			printf("\tEl fildes_counter es: %i\n", fildes_counter);
			printf("\tEl argv_counter es: %i\n\n", argv_counter);
			argv_counter++;
			fildes_counter++;
		}*/
		printf("\n");
	}
	return (0);
}
