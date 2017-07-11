/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:09:04 by douglas           #+#    #+#             */
/*   Updated: 2017/07/07 14:10:52 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_node(t_list *node)
{
	free(node->content);
	free(node);
}

void	ft_free_list(t_list *start)
{
	ft_lstiter(start, free_node);
}