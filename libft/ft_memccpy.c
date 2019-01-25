/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:01:44 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 17:20:50 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*sdst;
	const unsigned char	*ssrc;
	size_t				i;

	sdst = (unsigned char*)dst;
	ssrc = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		sdst[i] = ssrc[i];
		if (ssrc[i] == (unsigned char)c)
			return ((void*)(sdst + i + 1));
		++i;
	}
	return (NULL);
}
