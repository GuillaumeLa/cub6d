/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:20:32 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/09 14:20:34 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	a;
	int	b;

	a = nb % 10;
	b = nb / 10;
	if (b)
		ft_putnbr_fd(b, fd);
	if (nb < 0)
	{
		if (!b)
			ft_putchar_fd('-', fd);
		a = -a;
	}
	ft_putchar_fd(a + '0', fd);
}
