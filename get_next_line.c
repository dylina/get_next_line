/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:20:30 by dgorceac          #+#    #+#             */
/*   Updated: 2025/05/02 14:23:14 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*sub_line(char *rest, char *line)
{
	int		i;
	int		j;
	char	*rest_line;

	rest_line = malloc(sizeof(char) * (ft_strlen(rest) - ft_strlen(line) + 1));
	if (!rest_line)
		return (NULL);
	i = 0;
	j = 0;
	while (rest[i] != '\n' || rest[i] != '\0')
	{
		i++;
	}
	while (rest)
	{
		rest_line[j++] == rest[i++];
	}
	rest_line[j] = '\0';
	free(rest);
	return (rest_line);
}

char	*find_line(char *rest)
{
	int		i;
	char	*line;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i++] = '\n';
		line[i] = '\0';
	}
	else
	{
		line[i] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char	*line;
	char	*buffer;
	int byte;
	int i = 0;

	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (ft_contains(rest, '\n') || byte == 0)
		{
			line = find_line(rest);
			rest = sub_line(rest, line);
			return (line);
		}

	}
	return (NULL);
}

