/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:30:24 by yusong            #+#    #+#             */
/*   Updated: 2021/05/11 03:40:33 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		temp_dest[i] = temp_src[i];
		if (temp_src[i] == (unsigned char)c)
			break ;
		i++;
	}
	if (num == i)
		return (0);
	return (&temp_dest[i + 1]);
}
