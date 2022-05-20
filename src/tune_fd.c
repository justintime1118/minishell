// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   tune_fd.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/04/29 20:13:47 by yusong            #+#    #+#             */
// /*   Updated: 2022/05/01 11:52:34 by yusong           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// char	tune_fd1(char *cmd, int *fd, int dep)
// {
// 	if (dep != 0)
// 		if (dup2(STDOUT_FILENO, fd[1]) == -1)
// 			return (FAIL);
// 	if (dup2(STDIN_FILENO, fd[0]) == -1)
// 		return (FAIL);
// 	return (SUCCESS)
// }

// char	tune_fd2(char *cmd, int *fd, int dep)
// {
// 	int	file_fd;

// 	file_fd = open()
// }

// char	tune_fd3(char *cmd, int *fd, int dep)
// {

// }

// char	tune_fd4(char *cmd, int *fd, int dep)
// {

// }

// char	tune_fd(char **cmd, int *fd, int dep)
// {
// 	if (!ft_strncmp(cmd[dep], "|", 1) && ft_strlen(cmd[dep]) == 1)
// 		if (tune_fd1(cmd, fd, dep))
// 			return (FAIL);
// 	else if (!ft_strncmp(cmd[dep], ">>", 2) && ft_strlen(cmd[dep]) == 2)
// 		if (tune_fd2(cmd, fd, dep))
// 			return (FAIL);
// 	else if (!ft_strncmp(cmd[dep], ">", 1) && ft_strlen(cmd[dep]) == 1)
// 		if (tune_fd3(cmd, fd, dep))
// 			return (FAIL);
// 	else if (!ft_strncmp(cmd[dep], "<", 1) && ft_strlen(cmd[dep]) == 1)
// 		if (tune_fd4(cmd, fd, dep))
// 			return (FAIL);
// 	return (SUCCESS);
// }
