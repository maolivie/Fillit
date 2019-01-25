/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:34:28 by maolivie          #+#    #+#             */
/*   Updated: 2019/01/25 18:43:10 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		list_clear(t_tetri *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			free(lst->prev);
		}
		free(lst);
	}
}

void		init_list_data(t_tetri *lst)
{
	char	letter;

	letter = 'A';
	while(lst)
	{
		lst->flag = 1;
		lst->letter = letter++;
		lst = lst->next;
	}
}

static void	fill_coord(char *buf, t_tetri *tetri)
{
	short	*ptr;
	int		i;
	short	xmin;
	short	ymin;

	ptr = (short*)tetri;
	i = 0;
	xmin = 4;
	ymin = 4;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if ((*(ptr++) = i % 5) < xmin)
				xmin = i % 5;
			if ((*(ptr++) = i / 5) < ymin)
				ymin = i / 5;
		}
		++i;
	}
	while (ptr > (short*)tetri)
	{
		*(--ptr) -= ymin;
		*(--ptr) -= xmin;
	}
}

int			create_list(char *buf, int ret, t_tetri **alst)
{
	t_tetri	*lst;
	t_tetri	*tmp;

	*alst = NULL;
	tmp = NULL;
	while (ret > 0)
	{
		if ((lst = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
		{
			if (tmp)
				tmp->next = NULL;
			return (-1);
		}
		if (*alst == NULL)
			*alst = lst;
		fill_coord(buf, lst);
		lst->prev = tmp;
		if (lst->prev)
			lst->prev->next = lst;
		tmp = lst;
		ret -= 21;
		buf += 21;
	}
	lst->next = NULL;
	return (0);
}
