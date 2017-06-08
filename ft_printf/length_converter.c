/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:35:29 by douglas           #+#    #+#             */
/*   Updated: 2017/06/03 18:29:00 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		length_converter(va_list ap, int len)
{
	if (len == h)
		return (short)(va_arg(ap, int));
	if (len == hh)
		return (char)(va_arg(ap, int));
	if (len == l)
		return (va_arg(ap, long));
	if (len == ll)
		return (va_arg(ap, long long));
	if (len == j)
		return (va_arg(ap, uintmax_t));
	if (len == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, int));
}

size_t		ulength_converter(va_list ap, int len)
{
	if (len == h)
		return (unsigned short)(va_arg(ap, unsigned int));
	if (len == hh)
		return (unsigned char)(va_arg(ap, unsigned int));
	if (len == l)
		return (va_arg(ap, unsigned long));
	if (len == ll)
		return (va_arg(ap, unsigned long long));
	if (len == j)
		return (va_arg(ap, uintmax_t));
	if (len == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}
