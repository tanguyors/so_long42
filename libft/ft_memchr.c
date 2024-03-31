/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:12:16 by torsini           #+#    #+#             */
/*   Updated: 2024/03/01 16:50:34 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;
	unsigned char		uc;

	s_ptr = s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*s_ptr == uc)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
