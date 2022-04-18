/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 03:07:15 by yusong            #+#    #+#             */
/*   Updated: 2021/05/10 18:13:16 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		ret->content = content;
		ret->next = NULL;
	}
	return (ret);
}
