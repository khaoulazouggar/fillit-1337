/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:48:29 by kzouggar          #+#    #+#             */
/*   Updated: 2019/07/04 17:19:21 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	read_tetri(int fd, t_tetri *t)
{
	char	buff[22];
	int		r;
	int		i;
	int		count;

	i = -1;
	r = read(fd, buff, 21);
	buff[r] = '\0';
	count = ft_str_occurrence(buff, '\n');
	i = -1;
	if ((r == 20 && count == 4) || (r == 21 && count == 5))
		while (++i < 4)
			ft_memcpy(t->tetrimino[i], &buff[i * 5], 4);
	return ((r == 21 || r == 20) ? r : -1);
}

int	valide_tetri(t_tetri t)
{
	int point;
	int tag;
	int i;
	int j;

	i = -1;
	tag = 0;
	point = 0;
	while (++i < 4 && (j = -1))
		while (++j < 4)
		{
			tag += t.tetrimino[i][j] == '#';
			point += t.tetrimino[i][j] == '.';
		}
	return (((tag == 4 && point == 12)) ? 1 : 0);
}

int	check_validity(t_tetri t)
{
	int i;
	int j;
	int bloc;

	i = -1;
	bloc = 0;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if (t.tetrimino[i][j] == '#')
			{
				bloc += ((j + 1) < 4 && t.tetrimino[i][j + 1] == '#');
				bloc += ((j - 1) >= 0 && t.tetrimino[i][j - 1] == '#');
				bloc += ((i + 1) < 4 && t.tetrimino[i + 1][j] == '#');
				bloc += ((i - 1) >= 0 && t.tetrimino[i - 1][j] == '#');
			}
	return ((bloc == 6 || bloc == 8) ? 1 : 0);
}

int	tetris(int fd, t_tetris *k)
{
	int			r;
	int			count;
	t_tetri		t;

	count = 0;
	k->nbt = 0;
	while ((r = read_tetri(fd, &t)) != -1)
	{
		k->nbt++;
		if (k->nbt > 26)
			return (0);
		if (check_validity(t) && valide_tetri(t))
			k->tetrims[k->nbt - 1] = t;
		else
			return (0);
		if (r == 20)
			break ;
	}
	if (r != 20)
		return (0);
	return (1);
}
