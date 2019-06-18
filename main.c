/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:18:56 by kzouggar          #+#    #+#             */
/*   Updated: 2019/06/18 21:21:40 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	affiche(t_tetris t)
{
	int i;
	int j;

	i = -1;
	while (++i < t.taille)
	{
		j = -1;
		while (++j < t.taille)
			ft_putchar(t.tab[i][j]);
		ft_putchar('\n');
	}
}

int		main(int ac, char *av[])
{
	t_var		v;
	t_tetris	t;

	v.c = 'A';
	v.fd = open(av[1], O_RDONLY);
	if (ac != 2)
		ft_putstr("usage: fillit source_file\n");
	else if (!tetris(v.fd, &t))
		ft_putstr("error\n");
	else
	{
		v.i = -1;
		while (++v.i < t.nbt)
		{
			t.tetrims[v.i].c = v.c;
			mouve_tetri(&t.tetrims[v.i]);
			v.c++;
		}
		t.taille = ft_sqrt(t.nbt * 4);
		point_tab(&t);
		if (solve(&t, 0) == 0)
			t.taille++;
		affiche(t);
	}
	return (0);
}
