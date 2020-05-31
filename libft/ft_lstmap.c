/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 13:01:49 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/20 13:05:07 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((*f)(lst));
	temp = new;
	while (lst)
	{
		temp->next = ft_lstnew((*f)(lst));
		if (del)
			(*del)(lst->content);
		temp = temp->next;
		lst = lst->next;
	}
	return (new);
}
