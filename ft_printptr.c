/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:25:02 by jajin             #+#    #+#             */
/*   Updated: 2023/10/25 21:37:13 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_end;

	ptr_end = (unsigned long)ptr;
	ft_printstr("0x", counter);
	str = ft_aux_pf(ptr_end, HEX_LOW_BASE);
	ft_printstr(str, counter);
	free(str);
}