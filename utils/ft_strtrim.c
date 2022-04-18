/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:56:04 by yusong            #+#    #+#             */
/*   Updated: 2021/05/09 20:14:35 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	fill_ptr(int start, int end, char *s, char *ptr)
{
	size_t i;

	i = 0;
	while (start < end)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = 0;
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*temp;

	start = 0;
	if ((char *)s1 == NULL)
		return (NULL);
	if ((char *)set == NULL)
		return (ft_strdup((char *)s1));
	while (s1[start] && ft_strchr((char *)set, s1[start]))
		start++;
	if (start == ft_strlen((char *)s1))
		return (ft_strdup(""));
	end = ft_strlen((char *)s1);
	while (end && ft_strchr((char *)set, s1[end - 1]))
		end--;
	len = end - start + 1;
	if (!(temp = (char *)malloc(len)))
		return (NULL);
	fill_ptr(start, end, (char *)s1, temp);
	return (temp);
}
