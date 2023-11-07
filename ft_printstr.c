/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:03:53 by jajin             #+#    #+#             */
/*   Updated: 2023/10/25 20:40:31 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, size_t *counter)
{
	if (!str)
		str = NULL;
	while (*str)
	{
		ft_printchar(*str, counter);
		str++;
	}
}