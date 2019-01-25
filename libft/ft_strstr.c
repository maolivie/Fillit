/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:46:07 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 18:04:59 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		while (needle[i] == haystack[i] && needle[i])
			++i;
		if (!needle[i])
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}
