/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:55:21 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 01:27:49 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

t_list	*list_insert(t_list **root, t_list *list)
{
	t_list	*iter;

	iter = list_search(*root, list->key);
	if (iter)
	{
		free(iter->value);
		iter->value = list->value;
		free(list);
		return (iter);
	}
	list->next = *root;
	return (*root = list);
}
