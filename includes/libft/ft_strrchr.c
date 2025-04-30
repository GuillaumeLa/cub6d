/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:03:04 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/06 11:03:06 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	buffer ;
	int	i;

	buffer = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			buffer = i;
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	if (buffer == -1)
		return (0);
	else
		return ((char *)str + buffer);
}
