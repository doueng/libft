/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:10:59 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 12:08:20 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(int n)
{
	int count;

	count = 1;
	while ((n /= 10))
		count++;
	return (count);
}

static char		*exceptions(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char			*ft_itoa(int n)
{
	int		minus;
	int		len;
	char	*str;

	if (n == 0 || n == MIN_INT)
		return (exceptions(n));
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	len = get_len(n);
	len += minus;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	if (minus)
		str[0] = '-';
	str[len--] = '\0';
	while (n)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
