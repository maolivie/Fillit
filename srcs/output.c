/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:30:52 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/25 19:04:00 by maolivie         ###   ########.fr       */
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
				ft_putchar(tetri->letter);
			else if (tetri->b.x == j && tetri->b.y == i)
				ft_putchar(tetri->letter);
			else if (tetri->c.x == j && tetri->c.y == i)
				ft_putchar(tetri->letter);
			else if (tetri->d.x == j && tetri->d.y == i)
				ft_putchar(tetri->letter);
			else
				ft_putchar('.');
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

void		display_all_tetris(t_tetri *lst)
{
	while (lst)
	{
		display_a_tetri(lst);
		ft_putchar('\n');
		lst = lst->next;
	}
}
