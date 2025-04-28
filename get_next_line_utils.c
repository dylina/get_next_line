/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:21:49 by dgorceac          #+#    #+#             */
/*   Updated: 2025/04/28 20:43:27 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*new;
	size_t			i;
	size_t			j;
	size_t			len1;
	size_t			len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (unsigned char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return ((char *) new);
}

char	*ft_strdup(const char *source)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	i = 0;
	len = 0;
	while (source[len] != '\0')
		len++;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i <= len)
	{
		ptr[i] = source[i];
		i++;
	}
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*big;
	unsigned char	*new;
	size_t			i;
	size_t			str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + len > str_len)
		len = str_len - (size_t) start;
	big = (unsigned char *) s;
	new = (unsigned char *) malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = big[start + i];
		i++;
	}
	new[i] = '\0';
	return ((char *) new);
}
