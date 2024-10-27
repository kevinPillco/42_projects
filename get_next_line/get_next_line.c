#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <limits.h> // Para INT_MAX

char *get_text(int fd) 
{
	char *my_txt = malloc(BUFFER_SIZE);
	if (my_txt == NULL) 
		return NULL;

	int total_bytes = 0;
	int bytes_leidos;

	// Leer y almacenar el contenido del archivo
	while ((bytes_leidos = read(fd, my_txt + total_bytes, BUFFER_SIZE)) > 0) 
	{
		total_bytes += bytes_leidos;
		char *temp_txt = realloc(my_txt, total_bytes + BUFFER_SIZE + 1);
		if (temp_txt == NULL) 
		{
			free(my_txt);
			return NULL;
		}
		my_txt = temp_txt;
	}

	if (bytes_leidos == -1) 
	{
		free(my_txt);
		return NULL;
	}

	my_txt[total_bytes] = '\0';  // Null-terminar la cadena
	return my_txt;
}

char *get_next_line(int fd) 
{
	static char *my_txt = NULL;      // Contenido del archivo leído una vez
	static char **lines = NULL;      // Dividir el contenido en líneas
	static int current_line = 0;     // Índice de la línea actual a devolver

	if (my_txt == NULL) 
	{
		my_txt = get_text(fd);  // Leer el archivo completo
		if (my_txt == NULL)
			return NULL;                // Error de lectura
		lines = ft_split(my_txt, '\n');
	}

	char *line = lines[current_line];
	if (line == NULL)
	{
		free(my_txt);
		free(lines);
		my_txt = NULL;
		lines = NULL;
		current_line = 0;
		return NULL;
	}

	current_line++;                    // Avanzar a la siguiente línea
	return line;
}

