/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:03:59 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/18 02:52:05 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	if (!(node = f(lst)))
		return (NULL);
	lst = lst->next;
	start = node;
	while (lst)
	{
		if (!(node->next = f(lst)))
		{
			ft_lstdel(&start, ft_del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (start);
}
