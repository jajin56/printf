/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:42:34 by jajin             #+#    #+#             */
/*   Updated: 2023/10/25 20:52:36 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printdig(int num, size_t *counter)
{
    if (num == -2147483648)
    {
        ft_printdig((num / 10), counter);
        ft_printchar('8', counter);
    }
    else if (num < 0)
    {
        ft_printchar('-', counter);
        ft_printdig(-num, counter);
    }
    else
    {
        if (num > 9)
            ft_printdig((num / 10), counter);
        ft_printchar(('0' + num % 10), counter);
    }
}