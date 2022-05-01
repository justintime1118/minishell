/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:33:07 by yusong            #+#    #+#             */
/*   Updated: 2021/05/10 19:18:58 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t temp;

	i = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		temp = 0;
		if (s2[temp] == s1[i + temp])
		{
			while (s2[temp] && s1[i + temp])
			{
				if (s2[temp] != s1[i + temp] || (i + temp) >= len)
					break ;
				temp++;
			}
			if (s2[temp] == 0)
				return (&((char *)s1)[i]);
		}
		i++;
	}
	return ((void *)0);
}
