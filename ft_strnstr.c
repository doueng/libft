/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:14:46 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:14:46 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		ii;

	if (*little == '\0')
		return ((char*)big);
	while (*big && len)
	{
		i = 0;
		ii = 0;
		while ((len - i) && little[ii] && big[i] == little[ii])
		{
			ii++;
			i++;
		}
		if (little[ii] == '\0')
			return ((char*)big);
		big++;
		len--;
	}
	return (NULL);
}
