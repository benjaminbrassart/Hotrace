/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:21:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 14:40:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_btree	*btree_search(t_btree *root, t_hash hash)
{
	while (root && root->key != hash)
	{
		if (hash > root->key)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}
