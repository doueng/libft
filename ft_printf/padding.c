/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:45:13 by dengstra          #+#    #+#             */
/*   Updated: 2017/06/03 18:34:45 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*padding(char *str, t_id *id, size_t sign_len)
{
	size_t	width;
	size_t	str_len;
	void	*result;

	str_len = ft_strlen(str) + sign_len;
	if (id->specifier == 's' && id->has_precision)
		str_len = (id->precision < str_len) ? id->precision : str_len;
	width = (id->width > str_len) ? id->width : str_len;
	result = ft_strnew(width);
	if (!result)
		exit(-1);
	ft_memset(result, id->zero, width);
	if (!id->minus)
		ft_memmove(result + width - str_len, str, ft_strlen(str) + 1);
	else
		ft_memmove(result, str, str_len);
	return (result);
}
