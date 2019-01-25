/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:28:55 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 19:33:10 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((str = ft_strnew(len_s1 + len_s2)) == NULL)
		return (NULL);
	while (len_s2-- > 0)
		str[len_s1 + len_s2] = s2[len_s2];
	while (len_s1-- > 0)
		str[len_s1] = s1[len_s1];
	return (str);
}
