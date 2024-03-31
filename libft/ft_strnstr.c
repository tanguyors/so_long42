/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:54:34 by torsini           #+#    #+#             */
/*   Updated: 2024/03/07 15:11:45 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	unsigned long	i;
	int				j;

	j = 0;
	i = 0;
	if (!*n)
		return ((char *)h);
	while (h[i])
	{
		j = 0;
		while (h[i] == n[j] && h[i] && i < len)
		{
			i++;
			j++;
		}
		if (!n[j])
			return ((char *)&h[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
