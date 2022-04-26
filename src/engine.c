/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:51:00 by yusong            #+#    #+#             */
/*   Updated: 2022/04/26 21:11:33 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	engine(char **cmd, char **env)
{

}

char	loop(char **cmd, char **env)
{
	char	**cmd;
	int		ret;
	pid_t	child;

	while(true)
	{
		cmd = parse();
		child = fork()
		if (child == -1)
			return (FAIL);
		if (child == 0)
			if (engine(cmd, env))
				return (FAIL);
		else
			wait(&ret);
	}
}
