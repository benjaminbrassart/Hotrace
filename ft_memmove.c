/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:50:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 15:50:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, void const *src, unsigned int n)
{
	unsigned char		*d;
	unsigned char const	*s;

	d = dst;
	s = src;
	if (src > dst)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			d[n] = s[n];
	return (dst);
}
