/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 23:11:24 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/23 16:44:19 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	num;
	int	minus;

	minus = 1;
	num = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' && is_digit(*(str + 1)))
	{
		minus = -1;
		str++;
	}
	if (*str == '+' && is_digit(*(str + 1)))
		str++;
	while (*str != '\0' && is_digit(*str))
	{
		num = *str - '0' + num * 10;
		str++;
	}
	return (num *= minus);
}
