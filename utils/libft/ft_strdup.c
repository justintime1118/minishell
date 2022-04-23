/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:27:24 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/23 14:42:07 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}
