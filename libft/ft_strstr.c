/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 00:36:46 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/08 01:21:39 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *verif;
	char *ref;

	if (!*needle)
		return (char*)(haystack);
	while (*haystack)
	{
		ref = (char*)needle;
		if (*haystack == *ref)
		{
			verif = (char*)haystack;
			while (*verif++ == *ref++ && *(verif - 1) && *(ref - 1))
				;
			if (!*(ref - 1))
				return (char*)(haystack);
		}
		haystack++;
	}
	return (NULL);
}
