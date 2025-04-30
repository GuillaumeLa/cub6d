/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:58:50 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/06 10:58:54 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	void	*p;

	if (elementCount == 0 || elementSize == 0)
	{
		elementCount = 1;
		elementSize = 1;
	}
	if (elementCount > 65535 || elementSize > 65535
		|| elementCount * elementSize > 65535)
		return (NULL);
	p = malloc(elementCount * elementSize);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, elementCount * elementSize);
	return (p);
}
