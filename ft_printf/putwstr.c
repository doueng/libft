/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:33:14 by dengstra          #+#    #+#             */
/*   Updated: 2017/06/03 18:32:55 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_putwchar(wchar_t c, t_id *id)
{
	char	*result;

	if (c <= 127 || (id->specifier == 'c' && id->e_length == none))
		result = one_byte(c);
	else if (c <= 2047)
		result = two_byte(c);
	else if (c <= 65535)
		result = three_byte(c);
	else
		result = four_byte(c);
	return (result);
}

size_t		ft_putwstr(wchar_t *str, t_id *id)
{
	size_t	len;
	char	*result;
	char	*tmp;

	len = 0;
	if (!str)
		return (ft_putwstr(L"(null)", id));
	while (str[len++])
		;
	result = ft_strnew(len * 4);
	if (!result)
		exit(-1);
	while (*str)
	{
		tmp = ft_putwchar(*str++, id);
		ft_strcat(result, tmp);
		free(tmp);
	}
	len = ft_printstr(result, id);
	free(result);
	return (len);
}

int			ft_putbinary(size_t num)
{
	int len;

	len = 0;
	if (!num)
		return (0);
	len += ft_putbinary(num >> 8);
	if (num >> 8)
		len += write(1, " ", 1);
	len += ft_printf("%c%c%c%c%c%c%c%c",
			(num & 0b10000000) ? '1' : '0',
			(num & 0b01000000) ? '1' : '0',
			(num & 0b00100000) ? '1' : '0',
			(num & 0b00010000) ? '1' : '0',
			(num & 0b00001000) ? '1' : '0',
			(num & 0b00000100) ? '1' : '0',
			(num & 0b00000010) ? '1' : '0',
			(num & 0b00000001) ? '1' : '0');
	return (len);
}

int			ft_putzerochar(t_id *id)
{
	size_t width;

	width = 0;
	if (id->width)
		width = id->width - 1;
	if (id->minus)
	{
		ft_putchar(0);
		while (width--)
			ft_putchar(id->zero);
	}
	else
	{
		while (width--)
			ft_putchar(id->zero);
		ft_putchar(0);
	}
	return ((id->width) ? id->width : 1);
}
