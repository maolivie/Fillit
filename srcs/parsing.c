/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:37:18 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/07 13:23:44 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	power_of_2(short power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (2 * power_of_2(power - 1));
}

static short			check_format(char *buff)
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

static short			check_tetri(char *buff)
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

static void				parse_tetri(char *buff, short *tetris, short index)
{
	short			i;
	unsigned short	result;

	i = 0;
	result = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
			result += power_of_2(i - i / 5);
		i++;
	}
	tetris[index] = result;
}

short					parse_file(int fd, short **parsed)
{
	char	buff[21];
	short	tetri;
	short	ret;
	short	last_ret;

	if (!(*parsed = (short*)malloc(sizeof(short) * 27)))
		return (-1);
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
		parse_tetri(buff, *parsed, tetri);
		tetri++;
		last_ret = ret;
	}
	return (last_ret == 20 ? 0 : -1);
}
