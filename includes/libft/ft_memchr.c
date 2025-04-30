/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:59:57 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/06 10:59:59 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	char			*s_point;
	unsigned int	i;

	i = 0;
	s_point = (char *) s;
	while (i != n)
	{
		if (s_point[i] == (char) c)
			return ((void *)(s_point + i));
		i++;
	}
	return (0);
}
