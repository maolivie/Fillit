/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:55:50 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 18:55:31 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned short	nbr_len(int nbr)
{
	unsigned int	abs;
	unsigned short	len;

	len = 1;
	if (nbr < 0)
	{
		++len;
		abs = -nbr;
	}
	else
		abs = nbr;
	while (abs >= 10)
	{
		++len;
		abs /= 10;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	char			*str;
	unsigned int	abs;
	unsigned short	len;

	len = nbr_len(n);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		abs = -n;
	}
	else
		abs = n;
	while (abs >= 10)
	{
		str[--len] = abs % 10 + '0';
		abs /= 10;
	}
	str[--len] = abs + '0';
	return (str);
}
