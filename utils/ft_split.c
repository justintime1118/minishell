/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:42:39 by yusong            #+#    #+#             */
/*   Updated: 2021/05/13 18:00:22 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**free_array(char **temp)
{
	size_t i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (0);
}

static size_t		g_cnt(char const *s, char c)
{
	size_t i;
	size_t cnt;

	if (s == 0)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char				**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	char	*start;
	size_t	len;

	if (s == 0 || !(ret = (char **)malloc(sizeof(char *) * (g_cnt(s, c) + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			len = s - start + 1;
			if (!(ret[i] = (char *)malloc(sizeof(char) * len)))
				return (free_array(ret));
			ft_strlcpy(ret[i++], start, len);
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}
