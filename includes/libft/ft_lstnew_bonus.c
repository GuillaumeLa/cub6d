/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:24:41 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/14 13:24:43 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_new;

	list_new = malloc(sizeof(t_list));
	if (!list_new)
		return (0);
	list_new->content = content;
	list_new->next = NULL;
	return (list_new);
}
