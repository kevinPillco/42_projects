#include "get_next_line.h"

char	*get_text(int fd)
{
	char	*my_txt;
	char	*temp_txt;
	int		total_bytes;
	int		bytes_leidos;

	my_txt = malloc(BUFFER_SIZE + 1);
	if (my_txt == NULL)
		return (NULL);
	total_bytes = 0;
	bytes_leidos = read(fd, my_txt + total_bytes, BUFFER_SIZE);
	while (bytes_leidos > 0)
	{
		total_bytes += bytes_leidos;
		temp_txt = ft_realloc(my_txt, total_bytes + BUFFER_SIZE + 1);
		if (temp_txt == NULL)
		{
			free(my_txt);
			return (NULL);
		}
		my_txt = temp_txt;
		bytes_leidos = read(fd, my_txt + total_bytes, BUFFER_SIZE);
	}
	if (bytes_leidos == -1 || bytes_leidos == 0)
	{
		free(my_txt);
		return (NULL);
	}
	my_txt[total_bytes] = '\0';
	return (my_txt);
}

char	*get_next_line(int fd)
{
	static char	**lines;
	static int	current_line;
	char		*line;
	char		*my_txt;

	lines = NULL;
	if (lines == NULL)
	{
		my_txt = get_text(fd);
		if (my_txt == NULL)
			return (NULL);
		lines = ft_split(my_txt, '\n');
		free(my_txt);
		if (lines == NULL)
			return (NULL);
		current_line = 0;
	}
	line = lines[current_line];
	if (line == NULL)
	{
		free(lines);
		lines = NULL;
		current_line = 0;
		return (NULL);

	}
	current_line++;
	return (line);
}
