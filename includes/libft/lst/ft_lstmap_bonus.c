/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:13:25 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:13:26 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Iterates the list ’lst’ and applies the function ’f’ to the
// content of each element. Creates a new list resulting of the
// successive applications of the function ’f’. The ’del’ function
// is used to delete the content of an element if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_content;

	if (lst == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = ft_lstnew((*f)(lst->content));
		if (new_content == NULL)
		{
			ft_lstclear(&new_content, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_content);
		lst = lst->next;
	}
	return (new_lst);
}
