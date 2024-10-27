#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main() 
{
    int fd = open("test.txt", O_RDONLY);  // Abre el archivo test.txt
    if (fd == -1) 
    {
        perror("Error al abrir el archivo");
        return 1;  // Manejo de error al abrir el archivo
    }

    char *line;
	/*
	line = get_next_line(fd);
	printf("-------------------PRIMERA LINEA ---------------------"); 
    printf("%s\n", line);  // Imprimir cada línea
	line = get_next_line(fd);
	printf("-------------------SEGUNDA LINEA ---------------------"); 
    printf("%s\n", line);
	line = get_next_line(fd);
	printf("-------------------TERCERA LINEA ---------------------"); 	
    printf("%s\n", line);
	
	*/

	while (line != NULL)
	{
		printf("%s\n", line);
		line = get_next_line(fd);

	}
	

    close(fd);  // Cierra el archivo

    return 0;  // Finaliza el programa
}