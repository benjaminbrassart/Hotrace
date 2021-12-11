/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:55:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 01:03:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void	list_destroy(t_list **list)
{
	t_list	*iter;
	t_list	*slow;

	iter = *list;
	while (iter)
	{
		slow = iter->next;
		free(iter->value);
		free(iter);
		iter = slow;
	}
	*list = NULL;
}
