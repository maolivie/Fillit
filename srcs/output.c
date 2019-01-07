/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:30:52 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/07 17:38:44 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		display_a_tetri(unsigned short tetri)
{
	short	i;

	i = 16;
	while (--i >= 0)
	{
		if (tetri >= power_of_2(i))
		{
			write(1, "#", 1);
			tetri -= power_of_2(i);
		}
		else
			write(1, ".", 1);
		if (i % 4 == 0)
			write(1, "\n", 1);
	}
	return ;
}

void			display_all_tetris(unsigned short *parsed)
{
	short	i;

	i = 0;
	while (parsed[i])
	{
		display_a_tetri(parsed[i]);
		write(1, "\n", 1);
		++i;
	}
	return ;
}
