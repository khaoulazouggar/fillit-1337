/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:48:29 by kzouggar          #+#    #+#             */
/*   Updated: 2019/06/18 19:43:02 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_tetri(int fd, t_tetri *t)
{
	char	buff[22];
	int		r;
	int		i;
	int		count;
	char	*tmp;

	i = -1;
	count = 0;
	r = read(fd, buff, 21);
	buff[r] = '\0';
	while (buff[++i])
		if (buff[i] == '\n')
			count++;
	i = -1;
	if ((r == 20 && count == 4) || (r == 21 && count == 5))
	{
		while (++i < 4)
		{
			tmp = ft_strsub(buff, i * 5, 4);
			ft_strcpy(t->tetrimino[i], tmp);
			ft_strdel(&tmp);
		}
	}
	return ((r == 21 || r == 20) ? -1 : r);
}

int		valide_tetri(t_tetri t)
{
	int point;
	int tag;
	int i;
	int j;

	i = 0;
	tag = 0;
	point = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t.tetrimino[i][j] == '#')
				tag++;
			else if (t.tetrimino[i][j] == '.')
				point++;
			j++;
		}
		i++;
	}
	return (((tag == 4 && point == 12)) ? 1 : 0);
}

int		check_validity(t_tetri t)
{
	int i;
	int j;
	int bloc;

	i = -1;
	bloc = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (t.tetrimino[i][j] == '#')
			{
				if ((j + 1) < 4 && t.tetrimino[i][j + 1] == '#')
					bloc++;
				if ((j - 1) >= 0 && t.tetrimino[i][j - 1] == '#')
					bloc++;
				if ((i + 1) < 4 && t.tetrimino[i + 1][j] == '#')
					bloc++;
				if ((i - 1) >= 0 && t.tetrimino[i - 1][j] == '#')
					bloc++;
			}
		}
	}
	return ((bloc == 6 || bloc == 8) ? 1 : 0);
}

int		tetris(int fd, t_tetris *k)
{
	int		r;
	int		count;
	t_tetri	t;

	count = 0;
	k->nbt = 0;
	while ((r = read_tetri(fd, &t)) == -1)
	{
		k->nbt++;
		if (k->nbt > 26)
			return (0);
		if (check_validity(t) && valide_tetri(t))
			k->tetrims[k->nbt - 1] = t;
		else
			return (0);
	}
	if (r != 0)
		return (0);
	return (1);
}
