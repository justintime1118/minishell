/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:51:00 by yusong            #+#    #+#             */
/*   Updated: 2022/05/02 01:58:56 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	work_builtin(char **cmd, t_arraylist *env, int dep)
// {
// 	// switch builtin
// 	if (!ft_strncmp(cmd[dep], "echo", 4) && ft_strlen(cmd[dep]) == 4)
// 		return (ft_echo(cmd));
// 	else if (!ft_strncmp(cmd[dep], "exit", 4) && ft_strlen(cmd[dep]) == 4)
// 		return (ft_exit(cmd));
// 	else if (!ft_strncmp(cmd[dep], "pwd", 3) && ft_strlen(cmd[dep]) == 3)
// 		return (ft_pwd());
// 	else if (!ft_strncmp(cmd[dep], "unset", 5) && ft_strlen(cmd[dep]) == 5)
// 		return (ft_unset(env, cmd));
// 	else if (!ft_strncmp(cmd[dep], "export", 6) && ft_strlen(cmd[dep]) == 6)
// 		return (ft_export(env, cmd));
// 	else if (!ft_strncmp(cmd[dep], "env", 3) && ft_strlen(cmd[dep]) == 3)
// 		return (ft_env(env));
// 	else if (!ft_strncmp(cmd[dep], "cd", 2) && ft_strlen(cmd[dep]) == 2)
// 		return (ft_cd(cmd));
// }
char	rp_checker(char *s)
{
	if ((!ft_strncmp(s, ">", 1) && ft_strlen(s) == 1) || \
		(!ft_strncmp(s, "<", 1) && ft_strlen(s) == 1) || \
		(!ft_strncmp(s, ">>", 2) && ft_strlen(s) == 2) || \
		(!ft_strncmp(s, "|", 1) && ft_strlen(s) == 1))
		return (0);
	return (1);
}

char	*command_combine_option(char **cmd, int *dep)
{
	char	*ret;
	char	*front;
	char	*tmp;
	int		i;

	i = *dep;
	if (cmd[i] == NULL)
		return (NULL);
	ret = ft_strdup(cmd[i]);
	i++;
	while (cmd[i] && rp_checker(cmd[i]))
	{
		front = ft_strjoin(cmd[i], " ");
		tmp = ret;
		ret = ft_strjoin(front, ret);
		free(tmp);
		free(front);
		i++;
	}
	*dep = i;
	return (ret);
}

char	work_unit(char **cmd, t_arraylist *env, int *fd, int dep)
{
	pid_t	child;
	char	*now_cmd;
	int		idx;

	idx = dep;
	now_cmd = command_combine_option(cmd, &idx);
	if (now_cmd == NULL)
		exit(0);
	//tune_fd(cmd, fd, idx);
	child = fork();
	if (child == 0)
		work_unit(cmd, env, fd, idx + 1);
	else
	{
		wait(NULL);
		// // // path 설정 있는지 확인
		// // // 빌트인 명령어
		char *c[5] = {
			"/bin/bash",
			"-c",
			now_cmd,
			NULL
		};
		execve(c[0], c, env->str_arr);
	}
	return (FAIL);
}


char	engine(t_arraylist *env)
{
	char	**cmd;
	int		fd[2];
	pid_t	child;
	int		ret;

	pipe(fd);
	child = fork();
	if (child == 0)
	{
		cmd = parse();
		command_work(cmd, env);
		work_unit(cmd, env, fd, 0);
	}
	else
		wait(&ret);
	return (ret);
}

char	loop(t_arraylist *env)
{
	int		ret;

	while(1)
		ret = engine(env);
}
