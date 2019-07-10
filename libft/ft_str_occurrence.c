/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_occurrence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:50:31 by lsoulima          #+#    #+#             */
/*   Updated: 2019/07/03 10:52:39 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_occurrence(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
		count += (*s++ == c);
	return (count);
}
