# Nombre del ejecutable
NAME = get_next_line

# Compilador
CC = gcc

# Opciones del compilador
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SRCS = get_next_line.c get_next_line_utils.c ft_split.c main.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Regla principal para compilar el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .c a .o
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS)

# Regla para eliminar el ejecutable y archivos .o
fclean: clean
	rm -f $(NAME)

# Regla para recompilar el proyecto
re: fclean $(NAME)

# Regla para ejecutar el programa
run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
