/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:18:12 by douglas           #+#    #+#             */
/*   Updated: 2017/07/12 14:31:12 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_color(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(NORMAL_COLOR);
}
