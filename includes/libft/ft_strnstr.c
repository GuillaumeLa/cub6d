/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:54 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/06 11:02:56 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && n == 0)
		return (0);
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i != n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) != n)
		{
			j++;
			if (!to_find[j])
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
