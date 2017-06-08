/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:27:35 by douglas           #+#    #+#             */
/*   Updated: 2017/06/05 18:03:00 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		chars_printed;
	va_list	ap;
	t_id	*id;

	id = ft_get_flags((char*)format);
	input_checker(id);
	va_start(ap, (char*)format);
	chars_printed = ft_printer((char*)format, id, ap);
	va_end(ap);
	return (chars_printed);
}
