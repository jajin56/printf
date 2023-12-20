/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:03:10 by jajin             #+#    #+#             */
/*   Updated: 2023/12/20 16:56:36 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumbers(int c)
{
	int		len;
	char	*num;

	num = ft_itoa(c);
	len = ft_print_str(num);
	free(num);
	return (len);
}

static int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_printunsigned(unsigned int c)
{
	int		len;
	char	*num;

	len = 0;
	if (c == 0)
		len += ft_print_char('0');
	else
	{
		num = ft_unsigned_itoa(c);
		len += ft_print_str(num);
		free(num);
	}
	return (len);
}
