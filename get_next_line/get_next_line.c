/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:04:48 by cgaratej          #+#    #+#             */
/*   Updated: 2024/06/05 18:19:31 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFERR_SIZE
# define BUFERR_SIZE 42
#endif

int	ft_strlen(char *str)
{
	int	i = 0;

	if (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (str[i]);
		i++;
	}
	return (NULL);
}

char	ft_strcpy(char *dest, char *org)
{
	int	i = 0;
	
	while (org[i])
	{
		dest[i] = org[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *str)
{
	char	*cpy = malloc(ft_strlen(str) + 1);
	
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, str);
	return (cpy);
}

char *ft_strjoin(char *s1, char *s2)
{
	int		len1 = ft_strlen(s1);
	int		len2 = ft_strlen(s2);
	char	*str = malloc(len1 + len2 + 1);
	int		i = 0;
	int		j = 0;
	
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFERR_SIZE + 1];
	char *line;
	char *new_line;
	int bitys;
	int to_copy;
}