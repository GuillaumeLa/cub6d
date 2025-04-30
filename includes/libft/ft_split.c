/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:42:12 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/09 11:42:14 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_parse_words(char **result, char const *str, char sep)
{
	char const	*buffer;

	buffer = str;
	while (*buffer)
	{
		while (*str == sep)
			++str;
		buffer = str;
		while (*buffer && *buffer != sep)
			++buffer;
		if (*buffer == sep || buffer > str)
		{
			*result = ft_substr(str, 0, buffer - str);
			str = buffer;
			++result;
		}
	}
	*result = NULL;
}

static int	ft_get_words(char const *str, char sep)
{
	int	words_len;

	words_len = 0;
	while (*str)
	{
		while (*str == sep)
			++str;
		if (*str)
			++words_len;
		while (*str && *str != sep)
			++str;
	}
	return (words_len);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_get_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_parse_words(new, s, c);
	return (new);
}

// int main()
// {
// 	int i;
// 	char *str = "olol";
// 	char **result  = ft_split(str, ' ');
// 	while(i != 5)
// 	{
// 		printf("%s \n",result[i]);
// 		i++;
// 	}

// 	return 0;	
// }