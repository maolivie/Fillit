/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/06 19:40:01 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
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
	if (check_file(fd))
	{
		write(2, "Wrong file format !\n", 20);
		return (-1);
	}
	write(1, "File format correct !\n", 22);
	if (close(fd))
	{
		write(2, "Close() failed.\n", 16);
		return (-1);
	}
	return (0);
}
