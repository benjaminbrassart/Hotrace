/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:28:02 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/10 22:29:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

char	*ft_strdup(char const *s)
{
	unsigned int const	n = ft_strlen(s);
	char				*new;

	new = malloc(sizeof (*s) * (n + 1));
	if (new)
		ft_memmove(new, s, n + 1);
	return (new);
}
