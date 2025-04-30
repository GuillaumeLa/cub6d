/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:00:32 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/06 11:00:35 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int		i;
	unsigned char		*dest_point;
	const unsigned char	*src_point;

	i = 0;
	dest_point = dest;
	src_point = src;
	if (!dest && !src)
		return (0);
	if (dest_point < src_point)
	{
		while (n != i)
		{
			dest_point[i] = src_point[i];
			i++;
		}
	}
	else
	{
		while (n-- != 0)
			dest_point[n] = src_point[n];
	}
	return (dest);
}
