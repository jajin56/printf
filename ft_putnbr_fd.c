/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:03:10 by jajin             #+#    #+#             */
/*   Updated: 2023/11/07 14:03:16 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnbr(int n, size_t *counter)
{
	if (n == -2147483648)
	{
		ft_printnbr((n /10), counter);
		ft_printchar('8', counter);
	}
	else if (n < 0)
	{
		ft_printchar('-', counter);
		ft_printnbr(-n, counter);
	}
	else 
	{
		if (n > 9)
			ft_printnbr((n / 10), counter);
		ft_putchar_fd((n % 10 + '0'), counter);
	}
}
