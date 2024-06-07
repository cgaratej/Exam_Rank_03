/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:01:01 by cgaratej          #+#    #+#             */
/*   Updated: 2024/06/07 13:01:27 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void put_str(char *str, int *len)
{
	int i = 0;

	if (!str)
		str = "(null)";
	while(str[i])
	{
		(*len)++;
		write(1, &str[i], 1);
		i++;
	}
}

void put_nbr_base(long long int nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		(*len)++;
		write(1, "-", 1);
	}
	if (nbr >= base)
		put_nbr_base((nbr / base), base, len);
	(*len)++;
	write(1, &hex[nbr % base], 1);
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	int i = 0;
	va_list args;
	
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				put_str(va_arg(args, char *), &len);
			else if (format[i] == 'd')
				put_nbr_base((long long int)va_arg(args, int), 10, &len);
			else if (format[i] == 'x')
				put_nbr_base((long long int)va_arg(args, int), 16, &len);
		}
		else
		{
			len++;
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
int main(void)
{
	int ft;
	int pr;

	ft = ft_printf("hola, %d, %s, %x\n", 34, "buenas", 34);
	pr = printf("hola, %d, %s, %x\n", 34, "buenas", 34);
	printf("ft: %d, pr: %d\n", ft, pr);
}
