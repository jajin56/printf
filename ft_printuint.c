/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:08:39 by jajin             #+#    #+#             */
/*   Updated: 2023/11/07 14:09:00 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putuint_pf(unsigned int num, size_t *counter)
{
	char	*str;

	str = ft_help(num, "0123456789");
	ft_putstr_pf(str, counter);
	free(str);
}