/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:46:43 by douglas           #+#    #+#             */
/*   Updated: 2017/05/22 22:19:41 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(size_t value, char *base)
{
	char	*result;
	size_t	len;
	size_t	v;
	size_t	b;

	b = ft_strlen(base);
	v = value;
	len = 1;
	while (v /= b)
		len++;
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	while (len--)
	{
		result[len] = base[value % b];
		value /= b;
	}
	return (result);
}
