/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:38:26 by cloew             #+#    #+#             */
/*   Updated: 2021/12/10 23:03:54 by cloew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

static unsigned int	rol(unsigned int r, int k)
{
	return ((r << k) | (r >> (32 - k)));
}

unsigned int	hash(char const *input)
{
	unsigned int	result;

	result = 0x55555555;
	while (*input)
	{
		result ^= *input++;
		result = rol(result, 5);
	}
	return (result);
}
/*
int main(int argc, char **argv)
{
    unsigned int        i;

    i = hash(argv[1]);
    printf("%u\n", i);
}
*/
