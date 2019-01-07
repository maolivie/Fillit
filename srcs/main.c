/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/07 17:25:28 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int	process_input(int argc, char **argv, unsigned short **parsing)
{
	int		fd;

	if (argc != 2)
	{
		write(2, "usage: fillit source_file\n", 26);
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
	write(1, "File format correct !\n\n", 23);
	if (close(fd) == -1)
		write(2, "Close() failed.\n\n", 17);
	return (0);
}

int			main(int argc, char **argv)
{
	unsigned short	*tetris;

	if (process_input(argc, argv, &tetris) == -1)
		return (-1);
	display_all_tetris(tetris);
	free(tetris);
	return (0);
}
