#include "get_next_line.h"

int main() 
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1) 
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);

	return (0);
}
