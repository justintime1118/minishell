/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:45:07 by yusong            #+#    #+#             */
/*   Updated: 2021/05/11 02:23:12 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*temp;

	len = ft_strlen(str);
	temp = (char *)str;
	if (c == 0)
		return (&temp[len]);
	while (len--)
		if (temp[len] == (unsigned char)c)
			return (&temp[len]);
	return (NULL);
}
