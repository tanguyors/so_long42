/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:43:39 by torsini           #+#    #+#             */
/*   Updated: 2024/03/02 18:59:12 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	lng;
	char	*duplicate;
	size_t	i;

	if (s == NULL)
		return (NULL);
	lng = 0;
	while (s[lng] != '\0')
	{	
		lng++;
	}
	duplicate = malloc(sizeof(char) * (lng + 1));
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (i <= lng)
	{	
		duplicate[i] = s[i];
		i++;
	}
	return (duplicate);
}
