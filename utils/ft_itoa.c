/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:28:59 by yusong            #+#    #+#             */
/*   Updated: 2021/05/10 01:20:44 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_cnt(long x)
{
	int	i;

	if (x == 0)
		return (2);
	i = 0;
	if (x < 0)
		i++;
	while (x != 0)
	{
		i++;
		x /= 10;
	}
	return (i + 1);
}

static char	*make_ret(long x, int cnt)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(cnt)))
		return (NULL);
	if (x < 0)
	{
		ret[i++] = '-';
		x *= -1;
	}
	ret[--cnt] = '\0';
	while (i <= --cnt)
	{
		ret[cnt] = '0' + x % 10;
		x /= 10;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	long	temp;
	int		cnt;

	temp = n;
	cnt = digit_cnt(temp);
	return (make_ret(temp, cnt));
}
