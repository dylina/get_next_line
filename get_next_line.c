/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:20:30 by dgorceac          #+#    #+#             */
/*   Updated: 2025/05/06 15:32:44 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sub_line(char *rest)
{
	int		i;
	int		j;
	char	*rest_line;

	i = 0;
	j = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	rest_line = malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!rest_line)
		return (NULL);
	i++;
	while (rest[i])
		rest_line[j++] = rest[i++];
	rest_line[j] = '\0';
	free(rest);
	return (rest_line);
}

char	*find_line(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (rest[0] == '\0')
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
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
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_newfile(int fd, char *save)
{
	char	*buffer;
	int		reader;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	reader = 1;
	while (!ft_strchr(save, '\n') && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader <= -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = gnl_newfile(fd, save);
	if (!save)
		return (NULL);
	line = find_line(save);
	save = sub_line(save);
	return (line);
}
