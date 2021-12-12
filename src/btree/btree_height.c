/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 06:19:31 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 13:48:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	btree_height(t_btree *node)
{
	int	height_left;
	int	height_right;

	if (!node)
		return (0);
	height_left = 0;
	height_right = 0;
	if (node->left)
		height_left = btree_height(node->left);
	if (node->right)
		height_right = btree_height(node->right);
	if (height_right > height_left)
		return (height_right + 1);
	return (height_left + 1);
}

int	btree_balance_factor(t_btree *node)
{
	return (btree_height(node->left) - btree_height(node->right));
}
