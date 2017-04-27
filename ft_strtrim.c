/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:14:59 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:19:58 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	is_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char				*ft_strtrim(char const *s)
{
	unsigned int	needs_trim;
	unsigned int	len;
	char			*trimmed;

	if (!s)
		return (NULL);
	while (*s && is_white(*s))
		s++;
	if (!*s)
		return (ft_strnew(0));
	len = ft_strlen(s);
	needs_trim = 0;
	while (is_white(s[--len]))
		needs_trim = 1;
	if (needs_trim == 0)
		return (ft_strdup(s));
	trimmed = (char*)malloc(len + 2);
	if (!trimmed)
		return (NULL);
	trimmed[++len] = '\0';
	while (len--)
		trimmed[len] = s[len];
	return (trimmed);
}
