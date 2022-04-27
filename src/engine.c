/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:51:00 by yusong            #+#    #+#             */
/*   Updated: 2022/04/27 22:11:26 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *g_cmd[2] = {
	"usr",
	"bin"
}

char	work_unit(char **cmd, char **env, int *fd, int dep)
{
	int	child;

	if (cmd[dep] == NULL)
		return (0);
	child = fork();
	if (child == 0)
		work_unit(cmd, env, fd, dep + 1);
	wait(NULL);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	execve();
}

char	cmd_work()
{
	// add >> & > command change order

}

char	engine(char **cmd, char **env)
{
	int		fd[2];

	pipe(fd);
	// cmd_work();
	work_unit(cmd, env, fd, 0);
}

char	loop(char **cmd, char **env)
{
	char	**cmd;
	int		ret;

	while(true)
	{
		cmd = parse();
		ret = engine(cmd, env);
	}
}
