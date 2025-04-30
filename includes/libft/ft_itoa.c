/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:39:06 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/08 15:39:08 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sizeofint(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i = i + 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		a;

	len = ft_sizeofint(n);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	if (n == 0)
		result[0] = '0';
	result[len] = '\0';
	while (n != 0)
	{
		a = n % 10;
		if (a < 0)
		{
			a = a * -1;
			n = n * -1;
			result[0] = '-';
		}
		n = n / 10;
		result[len - 1] = a + '0';
		len--;
	}
	return (result);
}
