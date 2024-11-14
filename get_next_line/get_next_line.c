/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos <msantos@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:53:25 by msantos           #+#    #+#             */
/*   Updated: 2024/11/14 15:17:51 by msantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos = 0;
	static int bytes_read = 0;
	char *line = NULL;
	int line_len = 0;
	int line_size = 0;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return NULL;
	while (1)
	{
		if (buffer_pos >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (bytes_read <= 0)
				break;
		}
		if (line_len >= line_size) {
			line_size += BUFFER_SIZE;
			char *new_line = malloc(line_size);
			if (!new_line)
				return NULL;
			for (int j = 0; j < line_len; j++)
				new_line[j] = line[j];
			free(line);
			line = new_line;
		}
		line[line_len++] = buffer[buffer_pos++];
		if (line[line_len - 1] == '\n')
			break;
	}
	if (line)
		line[line_len] = '\0';
	return (line);
}*/
char *get_next_line(int fd)
{
	int  bytes_read;
	char *buffer;
	
	if (fd == -1 || BUFFER_SIZE >= 0)
		return (NULL);
	buffer = malloc (BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	return (buffer);
}

int main()
{
    char* fileName = "../hello.txt";
    int fd = open(fileName, O_RDONLY);
	char *loop = "coise";
	int	i = 1;
	
	while (loop != NULL)
	{
		loop = get_next_line(fd);
		printf("%d:%s\n",i, loop);
		i++;
	}
	close(fd);
    return (0);
}
