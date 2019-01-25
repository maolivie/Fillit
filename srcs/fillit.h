/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:49:28 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/25 09:59:41 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <libft.h>

typedef struct	s_dot
{
	short x;
	short y;
}				t_dot;
typedef struct	s_tetri
{
	t_dot			a;
	t_dot			b;
	t_dot			c;
	t_dot			d;
	char			letter;
	int				flag;
	struct s_tetri	*prev;
	struct s_tetri	*next;
}				t_tetri;

#endif