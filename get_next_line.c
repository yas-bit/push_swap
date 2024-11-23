/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:03:39 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/20 09:18:41 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinstr(char *line, char *buffer, int read_size, int index);
char	*readline(int fd, char *line, char *rest);
char	*return_next_line(char *line, char *rest);

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd == 1 || fd == 2)
		return (0);
	line = NULL;
	if (rest[0] != '\0')
		line = joinstr(rest, line, 0, 0);
	line = readline(fd, line, rest);
	if (!line)
		return (0);
	if (!*line && !*rest)
	{
		free (line);
		return (0);
	}
	line = return_next_line(line, rest);
	return (line);
}

char	*joinstr(char *line, char *buffer, int read_size, int index)
{
	char	*joined_line;
	int		i;

	i = 0;
	while (line && line[i])
		i++;
	joined_line = malloc(i + read_size + 1);
	i = 0;
	while (line && line[i])
	{
		joined_line[i] = line[i];
		i++;
	}
	while (buffer && *buffer)
	{
		joined_line[i] = *buffer;
		i++;
		buffer++;
	}
	if (index)
		free (line);
	joined_line[i] = '\0';
	return (joined_line);
}

char	*readline(int fd, char *line, char *rest)
{
	char	*buffer;
	int		read_size;

	read_size = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (read_size > 0 && !check_nl(line))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(buffer);
			free(line);
			rest[0] = 0;
			return (0);
		}
		buffer[read_size] = '\0';
		line = joinstr(line, buffer, read_size, 1);
	}
	free(buffer);
	return (line);
}

char	*return_next_line(char *line, char *rest)
{
	char	*new_line;
	int		line_size;
	int		i;
	int		j;

	i = 0;
	line_size = 0;
	j = 0;
	while (line[line_size] != '\n' && line[line_size])
		line_size++;
	if (line[line_size] == '\n')
		line_size++;
	new_line = malloc(line_size + 1);
	if (!new_line)
		return (0);
	new_line = fill (new_line, line, &i);
	while (line[i])
		rest[j++] = line[i++];
	rest[j] = '\0';
	free(line);
	return (new_line);
}
