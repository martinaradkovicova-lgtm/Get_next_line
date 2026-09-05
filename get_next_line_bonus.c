/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradkovi <mradkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:18:08 by mradkovi          #+#    #+#             */
/*   Updated: 2026/09/05 17:18:21 by mradkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include <stdio.h>

static char	*read_file_error(char	*static_storage, char *buffer);
static char	*read_file(int fd, char *static_storage);
static char	*extract_new_line(char *static_storage);
static char	*trim_static_storage(char *static_storage);

char	*get_next_line(int fd)
{
	static char	*static_storage[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	static_storage[fd] = read_file(fd, static_storage[fd]);
	if (static_storage[fd] == NULL)
		return (NULL);
	line = extract_new_line(static_storage[fd]);
	static_storage[fd] = trim_static_storage(static_storage[fd]);
	return (line);
}

static char	*read_file_error(char	*static_storage, char *buffer)
{
	free(static_storage);
	static_storage = NULL;
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
			return (read_file_error(static_storage, buffer));
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
/*
int main (int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (argc <= 2)
		printf("This function needs 2 args");
	
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	//1/1
	line = get_next_line(fd1);
	printf("FD 1: %s", line);
	free(line);

	//1/2
	line = get_next_line(fd2);
	printf("FD 2: %s", line);
	free(line);

	//2/1
	line = get_next_line(fd1);
	printf("FD 1: %s", line);
	free(line);

	//2/2
	line = get_next_line(fd2);
	printf("FD 2: %s", line);
	free(line);

	close(fd1);
	close(fd2);
	return (0);
}
*/
