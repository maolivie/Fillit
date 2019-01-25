/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:55:25 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 17:40:32 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t length;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	length = ft_strlen(needle);
	while (haystack[i] && i + length <= len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j])
			++j;
		if (!needle[j])
			return ((char*)(haystack + i));
		++i;
	}
	return (NULL);
}
