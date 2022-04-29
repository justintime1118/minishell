/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 01:22:11 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/30 01:23:42 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

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