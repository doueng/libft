/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:14:48 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:14:49 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *cpy;

	cpy = NULL;
	while (*s)
	{
		if (*s == (char)c)
			cpy = (char*)s;
		s++;
	}
	if (*s == (char)c)
		cpy = (char*)s;
	return (cpy);
}
