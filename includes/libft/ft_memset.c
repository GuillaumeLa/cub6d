/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:00:52 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/06 11:00:54 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, unsigned int count )
{
	unsigned int	i;
	char			*dest_pointed;

	i = 0;
	dest_pointed = (char *) pointer;
	while (count != i)
	{
		dest_pointed[i] = value;
		i++;
	}
	return (pointer);
}
