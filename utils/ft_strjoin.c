/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:14:17 by yusong            #+#    #+#             */
/*   Updated: 2021/05/10 23:47:18 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		ret[i++] = s2[j++];
	ret[i] = 0;
	return (ret);
}
