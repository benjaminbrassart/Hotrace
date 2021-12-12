/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:09:45 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 15:47:32 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>

int	ft_putstr(char const *s)
{
	unsigned int	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		++n;
	return (write(1, s, n));
}
