/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:21:40 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/14 13:21:43 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buffer;
	t_list	*buf_lst;

	if (!lst || !del)
		return ;
	buf_lst = *lst;
	buffer = *lst;
	while (buf_lst)
	{
		buffer = buffer->next;
		ft_lstdelone(buf_lst, del);
		buf_lst = buffer;
	}
	*lst = 0;
}
