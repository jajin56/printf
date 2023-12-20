/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajin <jajin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:41:34 by jajin             #+#    #+#             */
/*   Updated: 2023/12/20 16:56:04 by jajin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long long i)
{
	int	c;

	c = 1;
	while (i >= 10)
	{
		i /= 10;
		c++;
	}
	return (c);
}

static char	*ft_get_string(int *n, char *str, int *dig, long long *numb)
{
	int	c;

	c = *dig;
	str[c] = '\0';
	c--;
	while (c >= 0)
	{
		str[c] = *numb % 10 + 48;
		*numb /= 10;
		c--;
	}
	if (*n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	long long	numb;
	char		*str;
	int			i;
	int			dig;

	i = 0;
	numb = n;
	if (numb < 0)
	{
		numb *= -1;
		i++;
	}
	dig = ft_count(numb) + i;
	str = malloc(dig + 1);
	if (str == NULL)
		return (NULL);
	str = ft_get_string(&n, str, &dig, &numb);
	return (str);
}

int	ft_print_percent(void)
{
	int	len;

	len = 0;
	len += ft_print_char('%');
	return (len);
}
