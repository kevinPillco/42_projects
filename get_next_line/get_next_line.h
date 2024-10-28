#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char		*get_text(int fd);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
static int	count_words(char const *s, char c);
static char	*get_next_word(char const **s, char c);

#endif
