/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:46:14 by yusong            #+#    #+#             */
/*   Updated: 2022/04/30 10:08:03 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	command_env(char **cmd, char **env)
{
	size_t	i;
	size_t	idx;
	char	**kv;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i][0] == '$')
		{
			idx = get_element_idx(ARRAYLIST, &cmd[i][1]);
			kv = ft_split(ARRAYLIST[idx], '=');
			free(cmd[i]);
			cmd[i] = kv[1];
			free(kv[0]);
			free(kv);
		}
	}
}

void	command_redirection(char **cmd)
{
	
}

char	command_work(char **cmd, char **env)
{
	// fix < redirection
	command_env(cmd, env);
	command_reverse(cmd);
	return (SUCCESS);
}
