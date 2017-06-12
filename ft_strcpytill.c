/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpytill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 21:23:47 by douglas           #+#    #+#             */
/*   Updated: 2017/06/12 14:00:40 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpytill(char *str, char c)
{
	int		len;
	char	*result;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	result = ft_strnew(len);
	if (!result || !str[len])
		return (NULL);
	ft_strncpy(result, str, len);
	return (result);
}
