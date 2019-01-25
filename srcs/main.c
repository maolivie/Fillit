/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/25 11:34:06 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	process_input(int argc, char **argv, t_tetri **alst)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	if (parse_file(fd, alst) == -1)
	{
		write(1, "error\n", 6);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int			main(int argc, char **argv)
{
	t_tetri	*lst;

	if (process_input(argc, argv, &lst) == -1)
		return (-1);
	display_all_tetris(lst);
	free(lst);
	return (0);
}
