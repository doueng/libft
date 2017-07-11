/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:57:48 by douglas           #+#    #+#             */
/*   Updated: 2017/07/09 02:06:57 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_btree	*find_leftmost_node(t_btree *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

t_btree 		*btree_delone(t_btree *root, void *item, int (*cmp)(void *, void *),
					void (*free_node)(void *))
{
	t_btree *tmp;

	if (!root)
		return (NULL);
	if (cmp(root->item, item) > 0)
		root->right = btree_delone(root->right, item, cmp, free_node);
	else if (cmp(root->item, item) < 0)
		root->left = btree_delone(root->left, item, cmp, free_node);
	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free_node(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free_node(root);
			return (tmp);
		}
		tmp = find_leftmost_node(root->right);
		root->item = tmp->item;
		root->right = btree_delone(root, item, cmp, free_node);
	}
	return (root);
}
