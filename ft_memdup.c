/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 02:39:38 by douglas           #+#    #+#             */
/*   Updated: 2017/07/07 02:43:59 by douglas          ###   ########.fr       */
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