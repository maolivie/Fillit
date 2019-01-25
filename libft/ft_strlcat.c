/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:50:17 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 17:34:11 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	while (src[j])
		++j;
	if (size < i)
		return (size + j);
	return (i + j);
}
