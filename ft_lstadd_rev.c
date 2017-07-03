/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 21:20:49 by douglas           #+#    #+#             */
/*   Updated: 2017/07/02 00:20:50 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_rev(t_list **start, t_list *new)
{
	static t_list *current;

	if (!*start)
	{
		*start = new;
		current = new;
		return ;
	}
	current->next = new;
	current = new;
}