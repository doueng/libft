/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 21:39:46 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/06 22:09:14 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree *btree_create_node(void *item)
{
	t_btree *t;

	t = (t_btree*)malloc(sizeof(t_btree));
	t->left = NULL;
	t->right = NULL;
	t->item = item;
	return (t);
}
