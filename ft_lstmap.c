/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:11:16 by dengstra          #+#    #+#             */
/*   Updated: 2017/04/18 11:30:03 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;
	t_list	*chain;
	int		i;

	i = 0;
	first = NULL;
	while (lst)
	{
		new = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size);
		if (!new)
			return (NULL);
		if (i++ == 0)
		{
			first = new;
			chain = first;
		}
		lst = lst->next;
		chain->next = new;
		chain = chain->next;
	}
	return (first);
}
