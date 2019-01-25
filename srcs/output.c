/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:30:52 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/25 13:53:25 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	display_a_tetri(t_tetri *tetri)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri->a.x == j && tetri->a.y == i)
				write(1, "#", 1);
			else if (tetri->b.x == j && tetri->b.y == i)
				write(1, "#", 1);
			else if (tetri->c.x == j && tetri->c.y == i)
				write(1, "#", 1);
			else if (tetri->d.x == j && tetri->d.y == i)
				write(1, "#", 1);
			else
				write(1, ".", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}

void		display_all_tetris(t_tetri *lst)
{
	while (lst)
	{
		display_a_tetri(lst);
		write(1, "\n", 1);
		lst = lst->next;
	}
	return ;
}
