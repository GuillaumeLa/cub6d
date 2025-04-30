/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:24:31 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/14 13:24:33 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_result;
	t_list	*tempo;

	if (!lst || !f || !del)
		return (0);
	lst_result = NULL;
	while (lst)
	{
		tempo = ft_lstnew(f(lst->content));
		if (!tempo)
		{
			ft_lstclear(&lst_result, del);
			return (0);
		}
		ft_lstadd_back(&lst_result, tempo);
		lst = lst->next;
	}
	return (lst_result);
}
