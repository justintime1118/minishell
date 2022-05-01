/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:03:50 by yusong            #+#    #+#             */
/*   Updated: 2021/05/10 23:37:48 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(long x, int fd)
{
	if (x == 0)
		return ;
	rec(x / 10, fd);
	ft_putchar_fd('0' + x % 10, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = n;
	if (temp == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
		temp *= -1;
	}
	rec(temp, fd);
}
