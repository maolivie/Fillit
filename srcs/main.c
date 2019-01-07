/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/07 14:17:52 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	process_input(int argc, char **argv, unsigned short **parsing)
{
	int		fd;

	if (argc != 2)
	{
		write(2, "Wrong usage.\n", 13);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Open() failed.\nPlease try again with another file.\n", 51);
		return (-1);
	}
	if (parse_file(fd, parsing) == -1)
	{
		write(2, "Wrong file format (or malloc() failed) !\n", 41);
		free(*parsing);
		if (close(fd) == -1)
			write(2, "Close() failed.\n", 16);
		return (-1);
	}
	write(1, "File format correct !\n", 22);
	return (fd);
}

int			main(int argc, char **argv)
{
	int				fd;
	unsigned short	*tetris;

	if ((fd = process_input(argc, argv, &tetris)) == -1)
		return (-1);
	if (close(fd) == -1)
	{
		write(2, "Close() failed.\n", 16);
		return (-1);
	}
	return (0);
}
