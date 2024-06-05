/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:04:48 by cgaratej          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:39 by cgaratej         ###   ########.fr       */
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
}
