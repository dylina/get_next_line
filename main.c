#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>      // pentru open()
#include <unistd.h>     // pentru close()
#include <stdio.h>      // pentru printf()
#include <stdlib.h>     // pentru free()

char	*get_next_line(int fd); // asigură-te că ai prototipul

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Eroare la deschiderea fișierului");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // linia include deja '\n' dacă există
		free(line);
	}

	close(fd);
	return (0);
}

