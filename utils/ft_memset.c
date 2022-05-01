/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:05:10 by yusong            #+#    #+#             */
/*   Updated: 2021/05/09 20:15:42 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t count)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)dest;
	while (i < count)
		temp[i++] = (unsigned char)value;
	return (dest);
}
