/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:48:37 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:43:31 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	if (content == NULL)
	{
		new_list->content = 0;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = (void*)ft_memalloc(content_size);
		if (!new_list->content)
			return (0);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = 0;
	return (new_list);
}
