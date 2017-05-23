/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:57:22 by douglas           #+#    #+#             */
/*   Updated: 2017/05/22 20:02:55 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(int free1, char *s1, int free2, char *s2)
{
	char			*joined;
	unsigned int	i;
	unsigned int	ii;

	if (!s1 || !s2)
		return (NULL);
	joined = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	ii = 0;
	while (s1[ii])
		joined[i++] = s1[ii++];
	ii = 0;
	while (s2[ii])
		joined[i++] = s2[ii++];
	joined[i] = '\0';
	if (free1)
		free(s1);
	if (free2)
		free(s2);
	return (joined);
}
