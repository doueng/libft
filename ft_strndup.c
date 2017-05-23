/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:47:59 by douglas           #+#    #+#             */
/*   Updated: 2017/05/19 12:53:20 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*str;
	char	*temp;

	str = ft_strnew(len);
	if (!str)
		return (NULL);
	temp = str;
	while (len--)
		*temp++ = *src++;
	return (str);
}
