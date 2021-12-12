/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:45:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 15:46:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

char	*ft_strdup(char const *s)
{
	char			*new_s;
	unsigned int	n;

	n = 0;
	while (s[n])
		++n;
	new_s = malloc(sizeof (*new_s) * (n + 1));
	if (new_s)
		ft_memmove(new_s, s, n + 1);
	return (new_s);
}
