/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 12:08:10 by douglas           #+#    #+#             */
/*   Updated: 2017/07/07 13:56:26 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!(*root))
	{
		*root = btree_create_node(item);
		return ;
	}
	if ((*cmpf)((*root)->item, item) > 0)
		btree_insert(&(*root)->right, item, cmpf);
	if ((*cmpf)((*root)->item, item) <= 0)
		btree_insert(&(*root)->left, item, cmpf);
}
