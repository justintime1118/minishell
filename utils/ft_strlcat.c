/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:45:27 by yusong            #+#    #+#             */
/*   Updated: 2021/05/09 23:51:45 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	null_idx;
	size_t	i;

	i = 0;
	null_idx = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (destsize <= len_dest)
		return (len_src + destsize);
	while (*(dest + null_idx) != '\0')
		null_idx++;
	while (src[i] && i < destsize - 1 - len_dest)
	{
		dest[null_idx + i] = src[i];
		i++;
	}
	dest[null_idx + i] = 0;
	return (len_dest + len_src);
}
