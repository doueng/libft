/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_get_nth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:36:12 by douglas           #+#    #+#             */
/*   Updated: 2017/07/13 14:34:11 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_nth		*btree_get_nth(t_btree *root, t_nth *nth)
{
	if (!root)
		return (NULL);
	if (root->left)
		btree_get_nth(root->left, nth);
	if (nth->nth-- == 0)
	{
		nth->node = root;
		return (nth);
	}
	if (root->right)
		btree_get_nth(root->right, nth);
	return (nth);
}
