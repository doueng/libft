/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:58:25 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/25 14:51:16 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		strlen;
	int		i;
	int		ii;
	char	temp;

	strlen = 0;
	i = 0;
	while (str[i] != '\0')
		i++;
	strlen = i;
	strlen--;
	i = i / 2;
	ii = 0;
	while (i > 0)
	{
		temp = str[strlen];
		str[strlen] = str[ii];
		str[ii] = temp;
		strlen--;
		ii++;
		i--;
	}
	return (str);
}
