/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:54 by glabaden          #+#    #+#             */
/*   Updated: 2023/12/13 10:42:57 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	void	*p;

	if (elementCount == 0 || elementSize == 0)
	{
		elementCount = 1;
		elementSize = 1;
	}
	p = malloc(elementCount * elementSize);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, elementCount);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
