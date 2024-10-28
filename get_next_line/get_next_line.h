#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024  // Define el tamaño del buffer

// Funciones para manejar la memoria
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_realloc(void *ptr, size_t old_size, size_t new_size);

// Funciones para leer el archivo y dividir en líneas
char *get_text(int fd);
char **ft_split(char const *s, char c);
char *get_next_line(int fd);

#endif // GET_NEXT_LINE_H
