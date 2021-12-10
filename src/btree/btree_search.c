/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:21:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 00:24:13 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

t_btree	*btree_search(t_btree *root, t_hash hash)
{
	if (!root || root->key == hash)
		return (root);
	if (hash > root->key)
		return (btree_search(root->right, hash));
	return (btree_search(root->left, hash));
}
