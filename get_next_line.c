#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 83
#endif
/*
//
// Created by Rostyslav Druzhchenko on 05.09.2020.
//

#include <stdio.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <string.h>
#include <stdlib.h>

int malloc_counter = 0;

#define line_len 1024
typedef struct s_call {
    long address;
    unsigned long size;
    char line[line_len];
} t_call;

#define array_size 1024
t_call allocs_array[array_size];

static int total_leaks_size();
static void print_allocs();

// ================================== PUBLIC ==================================

void check_leaks() {
    if (malloc_counter != 0) {
        int total = total_leaks_size();
        fprintf(stderr,
                "\nLEAKS: there are %d leaks. TOTAL size: %d bytes\n\n",
                malloc_counter, total);
        print_allocs();
    }
}

// ================================= INTERNAL =================================

static void *(*real_malloc)(unsigned long) = 0;
static void (*real_free)(void *) = 0;

t_call *find_empty_position() {
    for (int i = 0; i < array_size; i++)
        if (allocs_array[i].address == 0)
            return &(allocs_array[i]);
    return 0;
}

static void add_call(t_call *call) {
    t_call *position = find_empty_position();
    if (position == 0) {
        fprintf(stderr, "There is no room left for `allocs_array`\n"
                        "Please increase its size\n");
        exit(1);
    }
    memcpy(position, call, sizeof(t_call));
}

static void remove_call(long address) {
    for (int i = 0; i < array_size; i++) {
        if (allocs_array[i].address == address) {
            allocs_array[i].address = 0;
            allocs_array[i].size = 0;
            allocs_array[i].line[0] = '\0';
            return;
        }
    }

    fprintf(stderr, "Trying to free memory that have already freed or "
                    "haven't ever allocated\n"
                    "Address 0x%lx not found in `allocs_array`\n", address);
    exit(2);
}

static void print_call(t_call *call) {
    fprintf(stderr, "Leak at address: 0x%lx | Leaked %ld bytes\n%s\n\n",
            call->address, call->size, call->line);
}

static void print_allocs() {
    for (int i = 0; i < array_size; i++)
        if (allocs_array[i].address != 0)
            print_call(&(allocs_array[i]));
}

static int total_leaks_size() {
    int total = 0;
    for (int i = 0; i < array_size; i++)
        if (allocs_array[i].address != 0)
            total += allocs_array[i].size;
    return total;
}

// ================================== MALLOC ==================================

static void malloc_init(void) {
    real_malloc = (void *(*)(unsigned long))dlsym(RTLD_NEXT, "malloc");
    if (real_malloc == 0)
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    memset(&allocs_array, 0, sizeof(allocs_array));
}

static char *split_to_only_func(char *s) {
    int len = strlen(s);
    int space_count = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ' ')
            space_count++;
        if (space_count == 3)
            return s + i;
    }
    return s;
}

static void cp_stack(char *dst, char **s_arr, int size) {
    int total_len = 0;
    for (int i = 0; i < size; i++) {
        char *function = split_to_only_func(s_arr[i]);
        int current_len = strlen(function);
        total_len += current_len;
        if (total_len + 2 > line_len)
            return;
        if (total_len != current_len) {
            dst[0] = '\n';
            dst += 1;
        }
        strncpy(dst, function, current_len + 1);
        dst += current_len;
    }
}

void *malloc(unsigned long size) {
    if (real_malloc == 0)
        malloc_init();

    void *p = 0;
    p = real_malloc(size);

    t_call call;
    call.address = (long)p;
    call.size = size;
    call.line[0] = '\0';

    void *callstack[128];
    int frames = backtrace(callstack, 128);
    char **strs = backtrace_symbols(callstack, frames);
    cp_stack(call.line, strs, frames);

    add_call(&call);
    malloc_counter++;
    return p;
}

// =================================== FREE ===================================

static void free_init(void) {
    real_free = (void (*)(void *))dlsym(RTLD_NEXT, "free");
    if (real_free == 0)
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
}

void free(void *p) {
    if (real_free == 0)
        free_init();

    remove_call((long)p);
    real_free(p);
    malloc_counter--;
}

// =================================== MINE ===================================

*/
void    ft_leaks(void)
{
    system("leaks fdf");
}

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
	ft_memset(ptr, '\0', total_spc);
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
	char		*buffer;
	//char		*string;
	size_t		readed;
	int			i;

	buffer = ft_calloc((BUFFER_SIZE - 5), sizeof(char));
	//string = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 0;
	printf("\t****%zd\n", fd);
	readed = read(fd, buffer, BUFFER_SIZE);
	printf("\tLos caracteres leidos %zd\n\n\n", readed);

	/*while (i <= 32)
	{
		write(1, &string[i], 1);
		buffer++;
		i++;
	}*/
	//ft_memcpy(string, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] != '\0')
	{
		write(1, &buffer[i], 1);
		buffer++;
	}

	printf("\n\n\n\n");
	//printf("\tLos caracteres leidos %s\n\n\n", string);
	//free(buffer);
	//free(string);
	//printf("\t%s\n", buffer);
	printf("\nsfdfsdfsdf\n");

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
	int		fides;
	char	*argumento;
	//static char 	*buff;

	fildes = NULL;
	argv_counter = 1;
	fildes_counter = 0;
	fides = 0;
	argumento = "quijote.txt";
	/*if (argc < 2)
	{
		printf("\n\tNo se ha proporcionado mingun argumento\n\n");
	}
	else
	{*/
		fildes = malloc((argc - 1) * sizeof(ssize_t));
		printf("\n\tEl numero de argumentos es: %i\n\n", argc - 1);
		//while (argv_counter < (argc))
		//{			
			fides = open(argumento, O_RDONLY);
			//fildes[fildes_counter] = open(argv[argv_counter], O_RDONLY);
			printf("\tEl argumento %d es: %s\n", argv_counter, argv[argv_counter]);
			printf("\tEl FD del argumento %d es: %zd\n", argv_counter, fildes[fildes_counter]);
			printf("\tEl fildes_counter es: %i\n", fildes_counter);
			printf("\tEl argv_counter es: %i\n\n\n", argv_counter);
			get_next_line(fides);
			//printf("\t -- %s", buff);
			argv_counter++;
			fildes_counter++;
		//}
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
	//}
	//check_leaks();
	//atexit(ft_leaks);
	return (0);
}
