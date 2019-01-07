/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/07 11:19:22 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	process_input(int argc, char **argv)
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
	if (parse_file(fd) == -1)
	{
		write(2, "Wrong file format !\n", 20);
		if (close(fd) == -1)
			write(2, "Close() failed.\n", 16);
		return (-1);
	}
	write(1, "File format correct !\n", 22);
	return (fd);
}

int			main(int argc, char **argv)
{
	int		fd;

	if ((fd = process_input(argc, argv)) == -1)
		return (-1);
	if (close(fd) == -1)
	{
		write(2, "Close() failed.\n", 16);
		return (-1);
	}
	return (0);
}
