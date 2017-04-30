/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:33:18 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/27 16:23:53 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, int size)
{
	void	*temp;

	if (!(temp = malloc(size)))
		return ;
	ft_memcpy(temp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, temp, size);
	free(temp);
}
