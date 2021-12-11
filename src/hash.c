/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:38:26 by cloew             #+#    #+#             */
/*   Updated: 2021/12/11 02:03:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_hash	rol(t_hash r, int k)
{
	return ((r << k) | (r >> (32 - k)));
}

t_hash	hash(char const *input)
{
	t_hash	result;

	result = 0x55555555;
	while (*input)
	{
		result ^= *input++;
		result = rol(result, 5);
	}
	return (result);
}
