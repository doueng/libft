/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:18:12 by douglas           #+#    #+#             */
/*   Updated: 2017/07/11 18:19:39 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lifbt.h"

void	ft_print_color(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(NORMAL_COLOR);
}
