/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:53:02 by douglas           #+#    #+#             */
/*   Updated: 2017/07/13 14:34:19 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_free(t_btree **root, void (*free_item)(void*))
{
	t_btree *r;

	r = *root;
	if (!r)
		return ;
	if (r->left)
		btree_free(&r->left, free_item);
	if (r->right)
		btree_free(&r->right, free_item);
	free_item(r->item);
	free(r);
	*root = NULL;
}
