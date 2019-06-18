/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 00:37:07 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/08 01:28:40 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*verif;
	char	*ref;
	size_t	i;

	if (!*needle)
		return (char*)(haystack);
	while (*haystack && len--)
	{
		i = len + 1;
		ref = (char*)needle;
		if (*haystack == *ref)
		{
			verif = (char*)haystack;
			while (*verif++ == *ref++ && *(verif - 1) && *(ref - 1) && i--)
				;
			if (!*(ref - 1))
				return (char*)(haystack);
		}
		haystack++;
	}
	return (NULL);
}
