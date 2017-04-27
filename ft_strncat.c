/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:58:30 by dengstra          #+#    #+#             */
/*   Updated: 2017/03/15 12:51:41 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char *answer;

	answer = dest;
	while (*dest)
		dest++;
	while (*src && nb)
	{
		*dest = *src;
		nb--;
		dest++;
		src++;
	}
	*dest = '\0';
	return (answer);
}
