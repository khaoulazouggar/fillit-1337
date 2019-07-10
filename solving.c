/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:15:43 by kzouggar          #+#    #+#             */
/*   Updated: 2019/06/25 22:41:03 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		deplace_tetris(t_tetris *t, int index_tetri, t_point p)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (p.x + t->tetrims[index_tetri].hashtag[i].x >= t->taille ||
				p.y + t->tetrims[index_tetri].hashtag[i].y >= t->taille)
			return (0);
		if (t->tab[p.x + t->tetrims[index_tetri].hashtag[i].x]
				[p.y + t->tetrims[index_tetri].hashtag[i].y] != '.')
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		t->tab[p.x + t->tetrims[index_tetri].hashtag[i].x]
			[p.y + t->tetrims[index_tetri].hashtag[i].y] =
			t->tetrims[index_tetri].c;
	}
	return (1);
}

void	delete_tetri(t_tetris *t, int index_tetri, t_point p)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		t->tab[p.x + t->tetrims[index_tetri].hashtag[i].x]
			[p.y + t->tetrims[index_tetri].hashtag[i].y] = '.';
	}
}

void	point_tab(t_tetris *t)
{
	int i;

	i = -1;
	while (++i < t->taille)
		ft_memset(t->tab[i], '.', t->taille);
}

int		solve(t_tetris *t, int i)
{
	int		x;
	int		y;
	t_point	p;

	x = -1;
	if (i == t->nbt)
		return (1);
	while (++x < t->taille)
	{
		y = -1;
		while (++y < t->taille)
		{
			p.x = x;
			p.y = y;
			if (deplace_tetris(&*t, i, p))
			{
				if (solve(t, i + 1))
					return (1);
				else
					delete_tetri(&(*t), i, p);
			}
		}
	}
	return (0);
}
