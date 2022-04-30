/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:51:00 by yusong            #+#    #+#             */
/*   Updated: 2022/04/30 10:12:18 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	work_builtin(char **cmd, int *fd, int dep)
{
	// switch builtin
	if (!ft_strncmp(cmd[dep], "echo", 4) && ft_strlen(cmd[dep]) == 4)
	else if (!ft_strncmp(cmd[dep], "exit", 4) && ft_strlen(cmd[dep]) == 4)
	else if (!ft_strncmp(cmd[dep], "pwd", 3) && ft_strlen(cmd[dep]) == 3)
	else if (!ft_strncmp(cmd[dep], "unset", 5) && ft_strlen(cmd[dep]) == 5)
	else if (!ft_strncmp(cmd[dep], "export", 6) && ft_strlen(cmd[dep]) == 6)
	else if (!ft_strncmp(cmd[dep], "env", 3) && ft_strlen(cmd[dep]) == 3)
	else if (!ft_strncmp(cmd[dep], "cd", 2) && ft_strlen(cmd[dep]) == 2)
}

char	work_unit(char **cmd, char **env, int *fd, int dep)
{
	int		child;

	if (cmd[dep] == NULL)
		exit(0);
	child = fork();
	if (child == 0)
		work_unit(cmd, env, fd, dep + 1);
	wait(NULL);
	work_builtin(cmd, fd, dep);
	// path 설정
	execve(tmp[0], tmp, env);
	return (FAIL);
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
