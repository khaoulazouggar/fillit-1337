/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 00:36:33 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/08 01:17:42 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		len_dest;
	int			limit;
	size_t		len_src;
	int			i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen((char*)src);
	if (size <= len_dest)
		return (size + len_src);
	limit = size - len_dest;
	i = -1;
	while (src[++i] && limit-- > 1)
		dest[len_dest + i] = src[i];
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}
