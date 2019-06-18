/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:44:44 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/18 00:29:19 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		(*node).content = NULL;
		(*node).content_size = 0;
	}
	else
	{
		if (!((*node).content = (void*)malloc(content_size)))
			return (NULL);
		(*node).content = ft_memcpy((*node).content, content, content_size);
		(*node).content_size = content_size;
	}
	(*node).next = NULL;
	return (node);
}
