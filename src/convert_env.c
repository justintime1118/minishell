/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:38:58 by yusong            #+#    #+#             */
/*   Updated: 2022/04/20 10:57:11 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	convert_env(t_list **head, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (make_el(head, env[i]))
			return (FAIL);
	return (SUCCESS);
}

static t_list	*make_el_lst(char *l, size_t i)
{
	size_t	len;
	size_t	j;
	size_t	k;
	char	*key;
	char	*value;
	t_list	*lst;

	len = ft_strlen(l);
	key = (char *)malloc(i + 1);
	value = (char *)malloc(len - i + 1);
	if (!key || !value)
		return (NULL);
	j = -1;
	while (++j < i)
		key[j] = l[j];
	key[j] = 0;
	k = 0;
	while (++j < len)
		value[k++] = l[j];
	value[k] = 0;
	lst = ft_lstnew(key, value);
	if (!lst)
		return (NULL);
	return (lst);
}

char	make_el(t_list **head, char *l)
{
	int		i;
	t_list	*lst;

	i = -1;
	while (l[++i])
		if (l[i] == '=')
			break ;
	lst = make_el_lst(l, i);
	if (!lst)
		return (FAIL);
	ft_lstadd_back(head, lst);
	return (SUCCESS);
}

// char	search_env(char *lst_env)
// {

// }
