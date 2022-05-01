/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:46:14 by yusong            #+#    #+#             */
/*   Updated: 2022/04/30 18:17:13 by yusong           ###   ########.fr       */
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

void	command_env(char **cmd, t_arraylist *env)
{
	size_t	i;
	size_t	idx;
	char	**kv;
	char	nil;

	nil = '\0';
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i][0] == '$')
		{
			idx = get_element_idx(env, &cmd[i][1]);
			if (idx == -1)
			{
				free(cmd[i]);
				cmd[i] = &nil;
				continue ;
			}
			kv = ft_split(env->str_arr[idx], '=');
			free(cmd[i]);
			cmd[i] = kv[1];
			free(kv[0]);
			free(kv);
		}
	}
}


char	command_work(char **cmd, t_arraylist *env)
{
	// fix < redirection
	command_env(cmd, env);
	command_reverse(cmd);
	return (SUCCESS);
}
