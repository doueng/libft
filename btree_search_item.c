/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:17:13 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/06 22:15:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void *res;
	
	if (!root)
		return (NULL);
	res = NULL;
	if (root->left)
		res = btree_search_item(root->left, data_ref, (*cmpf));
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	if (root->right)
		res = btree_search_item(root->right, data_ref, (*cmpf));
	return (res);
}
