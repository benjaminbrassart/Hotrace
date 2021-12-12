/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:44:55 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 15:50:07 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memset(void *dst, int c, unsigned int n)
{
	unsigned char		*d;
	unsigned char const	ch = c;

	d = dst;
	while (n--)
		*d++ = ch;
	return (dst);
}
