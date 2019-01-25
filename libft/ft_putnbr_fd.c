/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:13:15 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/17 17:06:37 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int abs;

	if (n < 0)
	{
		abs = -n;
		ft_putchar_fd('-', fd);
	}
	else
		abs = n;
	if (abs >= 10)
		ft_putnbr_fd(abs / 10, fd);
	ft_putchar_fd(abs % 10 + '0', fd);
}
