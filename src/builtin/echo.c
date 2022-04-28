/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:47:19 by yusong            #+#    #+#             */
/*   Updated: 2022/04/28 14:17:42 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_echo(char **cmd)
{
	char	flag;
	size_t	i;
	flag = ft_strncmp(cmd[1], "-n", ft_strlen(cmd[1]));
	if (flag)
		i = 1;
	else
		i = 0;
	while (cmd[++i])
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
	if (flag)
		write(STDOUT_FILENO, "\n", 1);
	return (SUCCESS);
}
