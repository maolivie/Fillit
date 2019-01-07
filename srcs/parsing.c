/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:37:18 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/07 11:20:29 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	check_format(char *buff)
{
	short	i;

	i = 0;
	while (i++ < 20)
	{
		if (!(i % 5) && buff[i - 1] != '\n')
			return (-1);
		if (i % 5 && buff[i - 1] != '#' && buff[i - 1] != '.')
			return (-1);
	}
	return (0);
}

static short	check_tetri(char *buff)
{
	short	i;
	short	sharp;
	short	link;

	i = 0;
	sharp = 0;
	link = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			sharp++;
			if (buff[i + 1] == '#')
				link++;
			if (i < 14 && buff[i + 5] == '#')
				link++;
		}
		i++;
	}
	if (sharp != 4 || link < 3)
		return (-1);
	return (0);
}

short			parse_file(int fd)
{
	char	buff[21];
	short	tetri;
	short	ret;
	short	last_ret;

	tetri = 0;
	last_ret = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		if (ret < 20 || tetri == 26)
			return (-1);
		if (check_format(buff) == -1)
			return (-1);
		if (check_tetri(buff) == -1)
			return (-1);
		if (ret == 21 && buff[20] != '\n')
			return (-1);
		tetri++;
		last_ret = ret;
	}
	return (last_ret == 20 ? 0 : -1);
}
