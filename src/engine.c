/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:51:00 by yusong            #+#    #+#             */
/*   Updated: 2022/04/28 16:02:35 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	work_unit(char **cmd, char **env, int *fd, int dep)
{
	int	child;

	if (cmd[dep] == NULL)
		return (0);
	child = fork();
	if (child == 0)
		work_unit(cmd, env, fd, dep + 1);
	wait(NULL);
	if (dep != 0)
		dup2(STDOUT_FILENO, fd[1]);
	dup2(STDIN_FILENO, fd[0]);
	char *tmp[4] = {
		"bin/zsh",
		"-c",
		cmd[dep],
		NULL
	};
	execve(tmp[0], tmp, env);
	return (FAIL);
}

size_t	command_counter(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

void	command_reverse(char **cmd)
{
	size_t	start;
	size_t	end;
	char *tmp;

	start = 0;
	end = command_counter(cmd) - 1;
	while (start < end)
	{
		tmp = cmd[start];
		cmd[start] = cmd[end];
		cmd[end] = tmp;
		start++;
		end--;
	}
}

char	command_work(char **cmd)
{
	// add >> & > command change order
	command_reverse(cmd);
	return (SUCCESS);
}

char	engine(char **cmd, char **env)
{
	char	**cmd;
	int		fd[2];

	pipe(fd);
	cmd = parse();
	command_work(cmd);
	work_unit(cmd, env, fd, 0);
	return (SUCCESS);
}

char	loop(char **env)
{
	int		ret;

	while(1)
	{
		ret = engine(cmd, env);
	}
}
