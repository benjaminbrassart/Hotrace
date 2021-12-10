/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:25:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/10 23:29:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

t_btree	*btree_create(char *strval)
{
	t_btree	*tree = malloc(sizeof (*tree));

	if (tree)
	{
		tree->strval = strval;
		tree->hashcode = hash_str(strval);
		tree->left = NULL;
		tree->right = NULL;
	}
	return (tree);
}
