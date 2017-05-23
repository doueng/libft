/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:55:51 by douglas           #+#    #+#             */
/*   Updated: 2017/05/22 14:02:42 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrfree(char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		ft_putchar(str[len++]);
	free(str);
	return (len);
}
