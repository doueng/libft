/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:17:13 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/12 18:04:25 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref, void *res,
							int (*cmpf)(void *, void *))
{
	if (!root)
		return (res);
	if (root->left)
		res = btree_search_item(root->left, data_ref, res, (*cmpf));
	if (res)
		return (res);
	if ((*cmpf)(root->item, data_ref) == 0)
		res = (root->item);
	if (root->right)
		res = btree_search_item(root->right, data_ref, res, (*cmpf));
	if (res)
		return (res);
	return (res);
}
