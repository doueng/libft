/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:49:14 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/23 17:26:42 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long	power_two;
	int		result;

	result = 1;
	power_two = 1;
	if (nb <= 0)
		return (0);
	while (power_two < nb)
	{
		power_two = result;
		power_two *= power_two;
		result++;
	}
	if (power_two == nb)
	{
		result--;
		return (result);
	}
	return (0);
}
