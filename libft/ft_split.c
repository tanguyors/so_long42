/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:58:20 by torsini           #+#    #+#             */
/*   Updated: 2024/03/02 17:07:29 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tan;
	size_t	word_lng;
	int		i;

	tan = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!s || !tan)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_lng = ft_strlen(s);
			else
				word_lng = ft_strchr(s, c) - s;
			tan[i++] = ft_substr(s, 0, word_lng);
			s += word_lng;
		}
	}
	tan[i] = NULL;
	return (tan);
}
