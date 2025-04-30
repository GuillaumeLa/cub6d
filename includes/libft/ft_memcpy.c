/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:01:40 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/06 11:01:42 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int count)
{
	unsigned int	i;
	char			*dest_pointed;
	char			*src_pointed;

	dest_pointed = (char *) dest;
	src_pointed = (char *) src;
	i = 0;
	if (!src && !dest)
		return (0);
	while (count != i)
	{
		dest_pointed[i] = src_pointed[i];
		i++;
	}
	return (dest);
}
