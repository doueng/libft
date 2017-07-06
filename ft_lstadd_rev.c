/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 21:20:49 by douglas           #+#    #+#             */
/*   Updated: 2017/07/06 16:47:37 by dengstra         ###   ########.fr       */
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
