/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:55:05 by torsini           #+#    #+#             */
/*   Updated: 2024/03/01 13:12:07 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nbre(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len ++;
		n = -n;
	}
	while (n >= 10)
	{
		len ++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	len = ft_len_nbre(n);
	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		sign = -sign;
	result = (char *)malloc(len + 1 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len --)
	{
		result[len] = '0' + (n % 10) * sign;
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
