/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:00:06 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/08 15:00:09 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	theoric_len;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size <= start)
		return (ft_strdup(""));
	theoric_len = size - start;
	if (theoric_len > len)
		theoric_len = len;
	new_str = (char *)malloc((theoric_len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = start;
	j = 0;
	while (i < size && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
