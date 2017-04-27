/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:14:56 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:14:57 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;
	char *result;

	if (!s)
		return (NULL);
	substr = (char*)malloc(len + 1);
	if (!substr)
		return (NULL);
	result = substr;
	s += start;
	while (len--)
		*substr++ = *s++;
	*substr = '\0';
	return (result);
}
