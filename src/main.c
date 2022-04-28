/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:44:34 by yusong            #+#    #+#             */
/*   Updated: 2022/04/28 14:24:28 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// only change lstnew.
// if you want to use other lst-fun, have to modify.

int	main(int argc, char **argv, char **env)
{
	char **cmd;

	loop(env);
	return (0);
}