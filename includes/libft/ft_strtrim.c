/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:26:28 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/08 16:26:30 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char charac, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == charac)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_parse(char *result, const char *chaine, int start, int end )
{
	int	i;

	i = 0;
	while (start != end)
	{
		result[i] = chaine[start];
		i++;
		start++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_inset(s1[start], set))
		start++;
	while (ft_inset(s1[end - 1], set))
		end--;
	if (end - start < 0)
	{
		start = 0;
		end = 0;
	}
	result = (char *) malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (0);
	result = ft_parse(result, s1, start, end);
	return (result);
}
