/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:40:09 by douglas           #+#    #+#             */
/*   Updated: 2017/06/06 13:50:18 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstr(char *str, t_id *id)
{
	char	*tmp;
	int		len;

	if (!str && !id->has_precision)
		return (ft_putstr("(null)"));
	if (id->specifier == '%')
		id->has_precision = 0;
	tmp = ft_strndup(str, (id->has_precision) ? id->precision : ft_strlen(str));
	if (!tmp)
		exit(-1);
	len = ft_putstrfree(padding(tmp, id, 0));
	free(tmp);
	return (len);
}
