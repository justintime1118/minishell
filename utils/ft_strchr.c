/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:24:45 by yusong            #+#    #+#             */
/*   Updated: 2021/05/11 02:23:13 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *temp;

	temp = (char *)str;
	if (c == 0)
		return (&temp[ft_strlen(temp)]);
	while (*temp)
	{
		if (*temp == (unsigned char)c)
			return (temp);
		temp++;
	}
	return (NULL);
}
