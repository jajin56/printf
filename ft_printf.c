/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:11:44 by jajin             #+#    #+#             */
/*   Updated: 2023/11/07 14:15:21 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_format(va_list va, char *str, size_t *counter)
{
    if (*str == 'c')
        ft_printchar(va_arg(va, int), counter);
    else if (*str == 's')
        ft_printstr(va_arg(va, char *), counter);
    else if (*str == 'p')
        ft_printptr(va_arg(va, void *), counter);
    else if (*str == 'i' || *str == 'd')
        ft_printnbr(va_arg(va, int), counter);
    else if (*str == 'u')
        ft_printuint(va_arg(va, unsigned int), counter);
    else if (*str == 'x' || *str == 'X')
    {
        if (*str == 'x')
            ft_printhex(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
        else
            ft_printhex(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
    }
    else if (*str == '%')
        ft_printchar(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list		va;
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &counter);
		}
		else
			ft_printchar(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}