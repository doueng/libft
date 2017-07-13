/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 02:39:38 by douglas           #+#    #+#             */
/*   Updated: 2017/07/13 14:33:23 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *mem, size_t size)
{
	void *result;

	if (!(result = (void*)malloc(size)))
		return (NULL);
	return (ft_memcpy(result, mem, size));
}
