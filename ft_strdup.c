/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:40:19 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:27:43 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*temp;
	int		len;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(len + 1);
	if (!str)
		return (0);
	temp = str;
	while (*src)
	{
		*temp = *src;
		src++;
		temp++;
	}
	*temp = '\0';
	return (str);
}
