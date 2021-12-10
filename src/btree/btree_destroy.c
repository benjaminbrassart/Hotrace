/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:32:00 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/10 23:33:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void	btree_destroy(t_btree *root)
{
	if (!root)
		return ;
	btree_destroy(root->left);
	btree_destroy(root->right);
	free(root->strval);
	free(root);
}
