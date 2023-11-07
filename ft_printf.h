/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:41:09 by jajin             #+#    #+#             */
/*   Updated: 2023/11/07 14:22:21 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

void	ft_printchar(char c, size_t *counter);
void	ft_printstr(char *str, size_t *counter);
void	ft_printdig(int num, size_t *counter);
void	ft_printuint(unsigned int num, size_t *counter);
void	ft_printhex(unsigned int num, size_t *counter, char *base);
void	ft_printptr(void *ptr, size_t *counter);

char    *ft_help(unsigned long long n, char *base);

#endif