/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:37:18 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/06 17:54:09 by maolivie         ###   ########.fr       */
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
			return (0);
		if (i % 5 && buff[i - 1] != '#' && buff[i - 1] != '.')
			return (0);
	}
	return (1);
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
		return (0);
	return (1);
}

short			check_file(int fd, char *buff)
{
	short	ret;
	short	last_ret;

	last_ret = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		last_ret = ret;
		if (ret < 20)
			return (0);
		if (!check_format(buff))
			return (0);
		if (!check_tetri(buff))
			return (0);
		if (ret == 21 && buff[20] != '\n')
			return (0);
	}
	return (last_ret == 20);
}
