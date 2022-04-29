/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:38:58 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/30 01:27:07 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../utils/libft/libft.h"
# include "../utils/arraylist.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


# define SUCCESS	0
# define FAIL		1

int	ft_cd(char *path);
int	ft_env(t_arraylist *arrlst);
int	ft_export(t_arraylist *arrlst, char *arg);
int	ft_unset(t_arraylist *arrlst, char *name);
char	ft_pwd(void);
char	ft_exit(char **cmd);

#endif