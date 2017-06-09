/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:14:50 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 12:35:05 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		count_words(char const *s, char c)
{
	unsigned int i;
	unsigned int words;

	if (!*s)
		return (0);
	i = 0;
	words = 0;
	while (s[i + 1])
	{
		if (s[i] != c && s[i + 1] == c)
			words++;
		i++;
	}
	if (s[i] != c)
		words++;
	return (words);
}

static const char		*skip_c(char const *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static unsigned int		word_len(char const *s, char c)
{
	unsigned int len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char				**spliter(const char *s, char c, char **split,
		unsigned int words)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (words--)
	{
		s = skip_c(s, c);
		len = word_len(s, c);
		split[i] = ft_strnew(len);
		if (!split[i])
			return (NULL);
		ft_memmove(split[i], s, len);
		split[i][len] = '\0';
		s += len;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned int	words;
	char			**split;

	if (!s)
		return (NULL);
	s = skip_c(s, c);
	words = count_words(s, c);
	split = (char**)malloc(sizeof(*split) * (words + 1));
	if (!split)
		return (NULL);
	return (spliter(s, c, split, words));
}
