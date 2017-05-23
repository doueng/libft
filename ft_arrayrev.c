/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 12:09:45 by douglas           #+#    #+#             */
/*   Updated: 2017/05/14 12:09:48 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arrayrev(void *a, size_t size, size_t len)
{
	int		i;
	int		ii;

	i = len / 2;
	len--;
	ii = 0;
	while (i-- > 0)
	{
		ft_swap(&a[len], &a[ii], size);
		len--;
		ii++;
	}
	return (a);
}
