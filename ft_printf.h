/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:41:09 by jajin             #+#    #+#             */
/*   Updated: 2023/12/20 16:45:25 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printnumbers(int c);
int		ft_print_format(va_list ap, const char format);
int		ft_print_str(char *str);
int		ft_printunsigned(unsigned int c);
int		ft_printhex(unsigned int c, const char format);
int		ft_printpointer(unsigned long ptr);
char	*ft_itoa(int n);
int		ft_print_char(int c);
int		ft_print_percent(void);

#endif