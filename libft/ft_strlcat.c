/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:17:09 by torsini           #+#    #+#             */
/*   Updated: 2024/03/01 12:46:58 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}	

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	destination_long;
	unsigned int	source_long;

	i = 0;
	destination_long = ft_strlen(dest);
	source_long = ft_strlen(src);
	if (size <= destination_long)
		return (size + source_long);
	while (src[i] && (destination_long + i) < (size - 1))
	{
		dest[destination_long + i] = src[i];
		i++;
	}
	dest[destination_long + i] = '\0';
	return (destination_long + source_long);
}
