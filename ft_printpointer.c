/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:25:02 by jajin             #+#    #+#             */
/*   Updated: 2023/12/20 16:45:45 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static int	ft_put_ptr(unsigned long num)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
	len += ft_ptr_len(num);
	return (len);
}

int	ft_printpointer(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		len += 5;
	}
	else
	{
		write(1, "0x", 2);
		len += 2;
		len += ft_ptr_len(ptr);
		ft_put_ptr(ptr);
	}
	return (len);
}
