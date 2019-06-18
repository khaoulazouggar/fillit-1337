/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:48:12 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/10 18:41:30 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tab;
	char	*tmp;
	int		size;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	tmp = (char*)s;
	tmp += (size = ft_strlen(tmp)) ? size - 1 : 0;
	while (*tmp == ' ' || *tmp == '\n' || *tmp == '\t')
		tmp--;
	if ((tab = ft_strnew(1 + size - ft_strlen(tmp))) == NULL)
		return (NULL);
	tab = ft_strncat(tab, (char *)s, tmp - s + 1);
	return (tab);
}
