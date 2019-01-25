/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:30:10 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 17:17:37 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	short	sign;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0') * sign;
	return (result);
}
