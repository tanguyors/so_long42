/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:40:53 by torsini           #+#    #+#             */
/*   Updated: 2024/03/03 17:06:48 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	if (nl > 100)
		ft_putnbr_fd(nl / 10, fd);
	else if ((nl / 10) > 0)
		ft_putchar_fd((nl / 10) + '0', fd);
	ft_putchar_fd((nl % 10) + '0', fd);
}	
