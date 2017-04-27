/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:14:32 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/23 13:49:09 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *dst;
	char *dst_start;

	if (!s || !f)
		return (NULL);
	dst = (char*)malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	dst_start = dst;
	while (*s)
		*dst++ = (*f)(*s++);
	*dst = '\0';
	return (dst_start);
}
