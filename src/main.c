/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:44:34 by yusong            #+#    #+#             */
/*   Updated: 2022/05/05 18:31:42 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// only change lstnew.
// if you want to use other lst-fun, have to modify.

int	main(int argc, char **argv, char **env)
{
	char **cmd;

	loop(create_arraylist(env));
	return (0);
}
