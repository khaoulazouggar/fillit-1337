/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:13:32 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/18 21:19:01 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*(char *)s == (char)c)
		return ((char *)s);
	return (NULL);
}
