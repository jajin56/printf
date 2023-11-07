/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:42:34 by jajin             #+#    #+#             */
/*   Updated: 2023/10/25 20:52:36 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned int num, size_t *counter, char *base)
{
	char	*str;

	str = ft_help(num, base);
	ft_printstr(str, counter);
	free(str);
}
