/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:30:59 by douglas           #+#    #+#             */
/*   Updated: 2017/06/01 12:40:12 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*one_byte(int c)
{
	char *result;

	result = ft_strnew(1);
	if (!result)
		exit(-1);
	result[0] = c;
	return (result);
}

char		*two_byte(int c)
{
	char *result;

	result = ft_strnew(2);
	if (!result)
		exit(-1);
	result[0] = (c >> 6 | 0b11000000) & 0b11011111;
	result[1] = (c | 0b10000000) & 0b10111111;
	return (result);
}

char		*three_byte(int c)
{
	char	*result;

	result = ft_strnew(3);
	if (!result)
		exit(-1);
	result[0] = (c >> 12 | 0b11100000) & 0b11101111;
	result[1] = (c >> 6 | 0b10000000) & 0b10111111;
	result[2] = (c | 0b10000000) & 0b10111111;
	return (result);
}

char		*four_byte(int c)
{
	char *result;

	result = ft_strnew(4);
	if (!result)
		exit(-1);
	result[0] = (c >> 18 | 0b11110000) & 0b11110111;
	result[1] = (c >> 12 | 0b10000000) & 0b10111111;
	result[2] = (c >> 6 | 0b10000000) & 0b10111111;
	result[3] = (c | 0b10000000) & 0b10111111;
	return (result);
}
