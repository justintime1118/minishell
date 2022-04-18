/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:38:17 by yusong            #+#    #+#             */
/*   Updated: 2021/05/12 13:47:53 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *after_f;
	t_list *ret;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		after_f = ft_lstnew(f(lst->content));
		if (!after_f)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, after_f);
		lst = lst->next;
	}
	return (ret);
}
