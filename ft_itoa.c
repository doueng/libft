/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:10:59 by dengstra          #+#    #+#             */
/*   Updated: 2017/06/04 16:10:46 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_len(long long n)
{
	size_t count;

	count = 1;
	while ((n /= 10))
		count++;
	return (count);
}

char				*ft_itoa(long long n)
{
	int			minus;
	long long	len;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	minus = 0;
	if (n < 0)
		minus = 1;
	len = get_len(n);
	if (!(str = ft_strnew(len + minus)))
		return (NULL);
	if (minus)
		str[0] = '-';
	while (n)
	{
		if (n < 0)
			str[len--] = ((n % 10) * -1) + '0';
		else
			str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
