/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:12:58 by dengstra          #+#    #+#             */
/*   Updated: 2017/03/15 11:14:05 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1)
	{
		while (s2[ii] && s1[i] == s2[ii])
		{
			ii++;
			i++;
		}
		if (s2[ii] == '\0')
			return ((char*)s1);
		s1++;
		i = 0;
		ii = 0;
	}
	return (NULL);
}
