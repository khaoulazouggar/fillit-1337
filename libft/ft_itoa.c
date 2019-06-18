/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:25:39 by kzouggar          #+#    #+#             */
/*   Updated: 2019/04/11 22:15:36 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;
	long	nb;

	nb = n;
	len = numlen(n) - 1;
	tab = ft_strnew(len + 1);
	if (tab == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		tab[0] = '-';
	}
	if (nb == 0)
		tab[0] = '0';
	while (nb)
	{
		tab[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (tab);
}
