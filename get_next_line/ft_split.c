#include "get_next_line.h"

static int	count_words(char const *s, char c)
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

static char	*get_next_word(char const **s, char c)
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
