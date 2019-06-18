/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:31:04 by kzouggar          #+#    #+#             */
/*   Updated: 2019/06/18 18:19:10 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	char		tetrimino[4][5];
	t_point		hashtag[4];
	char		c;
}				t_tetri;

typedef struct	s_tetris
{
	t_tetri		tetrims[26];
	int			nbt;
	char		tab[11][11];
	int			taille;
}				t_tetris;

typedef struct	s_var
{
	int			fd;
	int			i;
	char		c;
}				t_var;

int				read_tetri(int fd, t_tetri *t);
int				valide_tetri(t_tetri t);
int				check_validity(t_tetri t);
int				tetris(int fd, t_tetris *k);
int				search_tag(t_tetri t, char way);
void			mouve_tetri(t_tetri *t);
int				deplace_tetris(t_tetris *t, int index_tetri, t_point p);
void			delete_tetri(t_tetris *t, int index_tetri, t_point p);
void			point_tab(t_tetris *t);
void			affiche(t_tetris t);
int				solve(t_tetris *t, int i);
#endif
