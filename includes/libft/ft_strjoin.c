/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:18:19 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/08 15:18:23 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_new;
	int		i;
	int		j;
	char	*result;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	size_new = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *) malloc((size_new +1) * sizeof(char));
	if (result == NULL)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
	return (result);
}
