/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:04:48 by yusong            #+#    #+#             */
/*   Updated: 2022/04/27 10:39:12 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	change_order(char **cmd)
{
	char	*prev;
	char	*now;
	char	*next;

	
}

char	**parse(void)
{
	char	**cmd;

	cmd = ft_split(readline(">"), ' ');
	return (cmd);
}
