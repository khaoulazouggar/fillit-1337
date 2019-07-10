/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:18:56 by kzouggar          #+#    #+#             */
/*   Updated: 2019/06/25 22:44:38 by kzouggar         ###   ########.fr       */
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

void	free_map(char **map, int size)
{
	if (map != NULL)
	{
		while (size--)
			free(map[size]);
		free(map);
	}
}

char	**allocate_map(int size)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char *)ft_strnew(size)))
		{
			while (i--)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int		main(int ac, char *av[])
{
	t_var		v;
	t_tetris	t;

	v.solved = 0;
	v.fd = open(av[1], O_RDONLY);
	if (ac != 2)
		ft_putstr("usage: fillit source_file\n");
	else if (!tetris(v.fd, &t))
		ft_putstr("error\n");
	else
	{
		prepar_tetri(&t);
		t.taille = ft_sqrt(t.nbt * 4);
		while (v.solved == 0)
		{
			if (!(t.tab = allocate_map(t.taille)))
				return (-1);
			point_tab(&t);
			!(v.solved = solve(&t, 0)) ? t.taille++ : 0;
		}
		affiche(t);
		free_map(t.tab, t.taille);
	}
	return (0);
}
