/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:13:22 by yusong            #+#    #+#             */
/*   Updated: 2021/05/09 20:16:07 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *temp;

	if (!(temp = (char *)malloc(size * count)))
		return (NULL);
	ft_memset(temp, 0, size * count);
	return (temp);
}
