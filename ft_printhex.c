/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:42:34 by jajin             #+#    #+#             */
/*   Updated: 2023/12/20 16:47:55 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexnbrlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthex(unsigned int c, const char format)
{
	if (c <= 9)
		ft_print_char(c + 48);
	else
	{
		if (format == 'x')
			ft_print_char(c + 97 - 10);
		else if (format == 'X')
			ft_print_char(c + 65 - 10);
	}
}

int	ft_printhex(unsigned int c, const char format)
{
	int	len;

	len = 0;
	if (c == 0)
		len += ft_print_char('0');
	else if (c >= 16)
	{
		ft_printhex(c / 16, format);
		ft_printhex(c % 16, format);
	}
	else
		ft_puthex(c, format);
	len += ft_hexnbrlen(c);
	return (len);
}
