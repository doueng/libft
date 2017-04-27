/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:14:35 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:31:41 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	char			*dst_start;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	dst = (char*)malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	dst_start = dst;
	i = 0;
	while (*s)
		*dst++ = (*f)(i++, *s++);
	*dst = '\0';
	return (dst_start);
}
