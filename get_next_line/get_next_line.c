#include "get_next_line.h"

char *get_text(int fd) 
{
	char *my_txt = malloc(BUFFER_SIZE);  // Asignar memoria inicial para BUFFER_SIZE
	if (my_txt == NULL) 
	{
		return NULL;  // Fallo en malloc
	}

	int total_bytes = 0;
	int bytes_leidos;

	// Leer y almacenar el contenido del archivo
	while ((bytes_leidos = read(fd, my_txt + total_bytes, BUFFER_SIZE)) > 0) 
	{
		total_bytes += bytes_leidos;  // Acumular los bytes leídos
		char *temp_txt = realloc(my_txt, total_bytes + BUFFER_SIZE + 1); // Reasignar memoria para más contenido
		if (temp_txt == NULL) 
		{
			free(my_txt);
			return NULL;  // Fallo en realloc
		}
		my_txt = temp_txt;
	}

	if (bytes_leidos == -1) 
	{
		free(my_txt);  // Si hubo un error de lectura, liberar la memoria
		return NULL;
	}

	my_txt[total_bytes] = '\0';  // Null-terminar la cadena
	return my_txt;  // Retornar el contenido completo del archivo
}

char *get_next_line(int fd) 
{
	static char	**lines;
	static int	current_line;
	char		*line;
	char		*my_txt;

	if (lines == NULL)
	{
		my_txt = get_text(fd);
		if (my_txt == NULL)
			return (NULL);
		lines = ft_split(my_txt, '\n');
		free(my_txt);
		if (lines == NULL)
			return (NULL);
	}
	line = lines[current_line];
	if (line == NULL)
	{ // Si ya no hay más líneas
		free(lines);
		lines = NULL;
		current_line = 0;
		return NULL;
	}

	current_line++; // Avanzar a la siguiente línea
	return line;
}

