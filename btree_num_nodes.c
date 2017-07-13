/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_num_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:32:58 by douglas           #+#    #+#             */
/*   Updated: 2017/07/13 14:33:56 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			btree_num_nodes(t_btree *root)
{
	if (!root)
		return (0);
	return (btree_num_nodes(root->left) + btree_num_nodes(root->right) + 1);
}
