/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:37:18 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/25 11:33:40 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_tetri(char *buf)
{
	int		i;
	int		sharp;
	int		link;

	i = 0;
	sharp = 0;
	link = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			++sharp;
			if (buf[i + 1] == '#')
				++link;
			if (i < 14 && buf[i + 5] == '#')
				++link;
		}
		++i;
	}
	if (sharp != 4 || link < 3)
		return (-1);
	return (0);
}

static int	check_file(char *buf, int ret)
{
	int	i;

	while (ret > 0)
	{
		i = 0;
		while (i++ < 20)
		{
			if (i % 5 == 0 && buf[i - 1] != '\n')
				return (-1);
			if (i % 5 && buf[i - 1] != '#' && buf[i - 1] != '.')
				return (-1);
		}
		if (ret > 20 && buf[20] != '\n')
			return (-1);
		if (check_tetri(buf) == -1)
			return (-1);
		ret -= 21;
		buf += 21;
	}
	return (0);
}

void		put_coord(char *buf, t_tetri *tetri)
{
	short	*ptr;
	int		i;
	int		sharp;

	ptr = (short*)tetri;
	i = 0;
	sharp = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			*(ptr + sharp++) = i % 5; //this is GREEDY AF
			*(ptr + sharp++) = i / 5; //But if it does work then SMD
		}
		++i;
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
			return (-1);
		if (*alst == NULL)
			*alst = lst;
		put_coord(buf, lst);
		lst->prev = tmp;
		if (lst->prev)
			lst->prev->next = lst;
		tmp = lst;
		ret -= 21;
		buf += 21;
	}
	lst->next == NULL;
	return (0);
}

int			parse_file(int fd, t_tetri **alst)
{
	char	buf[546];
	int		ret;

	ret = read(fd, buf, 546);
	if (ret % 21 != 20)
		return (-1);
	if (check_file(buf, ret) == -1)
		return (-1);
	if (create_list(buf, ret, alst) == -1)
		return (-1);
	return (0);
}
