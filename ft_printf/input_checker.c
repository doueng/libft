/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:30:04 by dengstra          #+#    #+#             */
/*   Updated: 2017/06/05 17:57:40 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	input_checker(t_id *id)
{
	while (id)
	{
		if (id->specifier == 'u' && id->plus)
			id->plus = '\0';
		id = id->next;
	}
}
