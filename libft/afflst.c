/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afflst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 00:10:46 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/18 00:24:17 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	afflst(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("empty lst");
	while (lst)
	{
		ft_putstr((char *)lst->content);
		if (lst->next)
			ft_putstr(" -> ");
		lst = lst->next;
	}
}
