/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:11:20 by yusong            #+#    #+#             */
/*   Updated: 2021/05/13 19:52:09 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;
	size_t	length;

	i = 0;
	if (!s || ft_strlen(s) < start)
		return (ft_strdup(""));
	length = ft_strlen(s) - start + 1;
	if (length > len)
		length = len;
	if (!(temp = (char *)malloc(length + 1)))
		return (NULL);
	while (s[start + i] && i < length)
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
