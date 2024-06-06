/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:04:48 by cgaratej          #+#    #+#             */
/*   Updated: 2024/06/06 15:02:05 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strcpy(char *dest, char *org)
{
	int	i = 0;
	
	while (org[i])
	{
		dest[i] = org[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int 	len = ft_strlen(str);
	char	*cpy = malloc(len + 1);
	
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, str);
	return (cpy);
}

char *ft_strjoin(char *s1, char *s2)
{
	int		len1 = ft_strlen(s1);
	int		len2 = ft_strlen(s2);
	char	*join = malloc(len1 + len2 + 1);

	ft_strcpy(join, s1);
	ft_strcpy(join + len1, s2);
	free(s1);
	return (join);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *line;
	char *newline;
	int bytes;
	int to_copy;

	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (bytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bytes] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (!ft_strlen(line))
		return (free(line), NULL);
	if (newline)
	{
		to_copy = newline - line + 1;
		ft_strcpy(buf, newline + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buf[0] = '\0';
	}
	line[to_copy] = '\0';
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	(void)argc;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}*/