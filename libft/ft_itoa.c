/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:16:04 by facetint          #+#    #+#             */
/*   Updated: 2024/08/03 17:23:54 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../safe_alloc/allocator.h"

int	d_count(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	long	new;

	digit = d_count(n);
	new = n;
	str = (char *) safe_malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	else if (new < 0)
	{
		new = n;
		new *= -1;
		str[0] = '-';
	}
	while (new != 0)
	{
		digit--;
		str[digit] = (new % 10) + '0';
		new = new / 10;
	}
	return (str);
}
