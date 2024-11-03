#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest || !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

void *ft_realloc(void *ptr, size_t new_size) {
	// Si el nuevo tamaño es 0, liberamos la memoria y devolvemos NULL
	if (new_size == 0) {
		free(ptr);
		return (NULL);
	}
	
	// Si el puntero es NULL, simplemente asignamos un nuevo bloque de memoria
	if (ptr == NULL) {
		return (malloc(new_size));
	}

	// Intentamos asignar un nuevo bloque de memoria
	void *new_ptr = malloc(new_size);
	if (!new_ptr) {
		return (NULL);
	}

	memcpy(new_ptr, ptr, new_size);

	free(ptr);

	return (new_ptr);
}

int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	*get_next_word(char const **s, char c)
{
	const char	*start;
	char		*word;
	int			i;
	int			index;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	index = 0;
	while ((*s)[index] && (*s)[index] != c)
		index++;
	word = (char *)malloc((index + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < index)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	*s += index;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	tmp = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		tmp[i] = get_next_word(&s, c);
		if (!tmp[i])
		{
			while (i > 0)
				free(tmp[--i]);
			free(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
