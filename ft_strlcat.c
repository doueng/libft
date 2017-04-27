/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:09:59 by dengstra          #+#    #+#             */
/*   Updated: 2017/03/15 17:00:05 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = (ft_strlen(dst) <= size ? ft_strlen(dst) : size);
	if (dlen >= size)
		return (slen + size);
	size -= dlen;
	dst += dlen;
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (slen + dlen);
}
