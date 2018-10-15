/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:49:37 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:42:06 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
	{
		new_list = ft_lstmap(lst->next, f);
		ft_lstadd(&new_list, f(lst));
	}
	else
		new_list = f(lst);
	return (new_list);
}
