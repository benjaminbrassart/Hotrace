/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:54:38 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 00:58:42 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

t_list	*list_create(t_hash key, char *value)
{
	t_list	*list;

	list = malloc(sizeof (*list));
	if (list)
	{
		list->key = key;
		list->value = value;
	}
	return (list);
}
