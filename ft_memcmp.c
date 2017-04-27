/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:11:33 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:11:34 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_uc;
	unsigned char *s2_uc;

	s1_uc = (unsigned char*)s1;
	s2_uc = (unsigned char*)s2;
	while (n--)
	{
		if (*s1_uc != *s2_uc)
			return (*s1_uc - *s2_uc);
		s1_uc++;
		s2_uc++;
	}
	return (0);
}
