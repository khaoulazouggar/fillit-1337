/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:23:53 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/18 19:08:44 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strstart(char const **s, char c)
{
	int		end;
	char	*tab;

	end = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[end] && (*s)[end] != c)
		end++;
	tab = ft_strsub(*s, 0, end);
	while (**s && **s != c)
		(*s)++;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wrd;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	wrd = countwords((char *)s, c);
	if ((tab = (char **)malloc(sizeof(char *) * wrd + 1)) == NULL)
		return (NULL);
	while (wrd)
	{
		tab[i] = strstart(&s, c);
		i++;
		wrd--;
	}
	tab[i] = NULL;
	return (tab);
}
