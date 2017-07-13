/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:28:46 by douglas           #+#    #+#             */
/*   Updated: 2017/07/13 14:33:43 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_color(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(NORMAL_COLOR);
}
