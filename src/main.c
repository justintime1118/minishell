/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:44:34 by yusong            #+#    #+#             */
/*   Updated: 2022/04/20 10:58:01 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// only change lstnew.
// if you want to use other lst-fun, have to modify.

int	main(int argc, char **argv, char **env)
{
	// char **tmp;

	// int i = 0;
	// while (env[i])
	// {
	// 	printf("%s\n", env[i]);
	// 	i++;
	// }
	t_list	*head;
	// convert_env(head, env);
	head = NULL;
	convert_env(&head, env);
	while (head)
	{
		printf("%s %s\n", head->key, head->content);
		head = head->next;
	}
	return (0);
}