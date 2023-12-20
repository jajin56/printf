/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:11:44 by jajin             #+#    #+#             */
/*   Updated: 2023/12/20 16:39:42 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_format(va_list ap, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(ap, int));
	else if (format == 's')
		len += ft_print_str(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		len += ft_printnumbers(va_arg(ap, int));
	else if (format == 'u')
		len += ft_printunsigned(va_arg(ap, unsigned int));
	else if (format == 'p')
		len += ft_printpointer(va_arg(ap, unsigned long));
	else if (format == 'X' || format == 'x')
		len += ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_print_format(ap, format[i + 1]);
			i++;
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

/* #include <stdio.h>
int	main(void)
{
	char *str;
	str = "Hello";

	printf("%d", printf("%s", str));
	printf("\n%i", printf("%s", str));

	return (0);
} */