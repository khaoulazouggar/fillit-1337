/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:40:08 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/18 22:14:35 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen((char *)s);
	while (len--)
	{
		if ((char)s[len + 1] == (char)c)
			break ;
	}
	if ((char)s[len + 1] == (char)c)
		return ((char *)s + (len + 1));
	return (NULL);
}
