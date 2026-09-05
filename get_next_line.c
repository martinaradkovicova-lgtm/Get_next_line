#include "get_next_line.h"
#include <stdio.h>

static char	*read_error(char	*static_storage, char *buffer);
static char	*read_file(int fd, char *static_storage);
static char	*extract_new_line(char *static_storage);
static char	*trim_static_storage(char *static_storage);

char	*get_next_line(int fd)
{
	static char	*static_storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_storage = read_file(fd, static_storage);
	if (static_storage == NULL)
		return (NULL);
	line = extract_new_line(static_storage);
	static_storage = trim_static_storage(static_storage);
	return (line);
}

static char	*read_error(char	*static_storage, char *buffer)
{
	free(static_storage);
	free(buffer);
	return (NULL);
}

static char	*read_file(int fd, char *static_storage)
{
	char	*swap;
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (static_storage == NULL)
		static_storage = ft_strdup("");
	bytes_read = 1;
	while (!(ft_strchr(static_storage, '\n')) && (bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (read_error(static_storage, buffer));
		buffer[bytes_read] = '\0';
		swap = static_storage;
		static_storage = ft_strjoin(swap, buffer);
		free(swap);
	}
	free(buffer);
	return (static_storage);
}

static char	*extract_new_line(char *static_storage)
{
	size_t	i;
	char	*line;
	
	if (static_storage[0] == '\0')
		return (NULL);
	i = 0;
	while ((static_storage[i] != '\0') && (static_storage[i] != '\n'))
		i++;
	if (static_storage[i] == '\n')
		i++;
	line = ft_substr(static_storage, 0, i);
	return (line);
}

static char	*trim_static_storage(char *static_storage)
{
	char	*position;
	char	*swap;

	position = ft_strchr(static_storage, '\n');
	if (position == NULL)
	{
		free(static_storage);
		return (NULL);
	}
	swap = static_storage;
	static_storage = ft_strdup(position + 1);
	free(swap);
	return (static_storage);
}

/*int main (int argc, char **argv)
{
	int		fd;
	char	*line;
	
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf ("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	
	

	return (0);
	}*/
