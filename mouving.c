/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:14:56 by kzouggar          #+#    #+#             */
/*   Updated: 2019/07/04 17:20:09 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		search_tag(t_tetri t, char way)
{
	int i;
	int j;

	i = -1;
	if (way == 'x')
	{
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (t.tetrimino[i][j] == '#')
					return (i);
		}
	}
	else
	{
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (t.tetrimino[j][i] == '#')
					return (i);
		}
	}
	return (-1);
}

void	prepar_tetri(t_tetris *t)
{
	int	i;

	i = 0;
	while (i < t->nbt)
	{
		t->tetrims[i].c = 'A' + i;
		mouve_tetri(&t->tetrims[i++]);
	}
}

void	mouve_tetri(t_tetri *t)
{
	int		i;
	int		j;
	int		k;
	t_point	p;

	k = 0;
	i = -1;
	p.x = search_tag(*t, 'x');
	p.y = search_tag(*t, 'y');
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if (t->tetrimino[i][j] == '#')
			{
				t->tetrimino[i][j] = '.';
				t->tetrimino[i - p.x][j - p.y] = t->c;
				t->hashtag[k].x = i - p.x;
				t->hashtag[k].y = j - p.y;
				k++;
			}
}
