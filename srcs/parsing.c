/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:37:18 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/07 14:25:20 by maolivie         ###   ########.fr       */
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

static unsigned short	parse_tetri(char *buff)
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
	return (result);
}

short					parse_file(int fd, unsigned short **parsed)
{
	char	buff[21];
	short	tetri;
	short	ret;
	short	last_ret;

	if (!(*parsed = (unsigned short*)malloc(sizeof(unsigned short) * 27)))
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
		(*parsed)[tetri] = parse_tetri(buff);
		tetri++;
		last_ret = ret;
	}
	(*parsed)[tetri] = 0;
	return (last_ret == 20 ? 0 : -1);
}
