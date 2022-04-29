/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:19:27 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/30 01:29:02 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	ft_export(t_arraylist *arrlst, char *arg)
{
	char	*copy;
	size_t	i;
	int		idx;
	// 아무 인자없이 호출하면 환경변수 목록 출력
	if (*arg == '\0' || arg == NULL) // 나중에 적절히 수정하자
		return (ft_env(arrlst));
	// 인자로 들어온 값을 = 이전까지의 값만 남게끔 편집해서 환경변수 목록을 탐색함
	copy = ft_strdup(arg);
	i = 0;
	while (arg[i] != '=' && i < ft_strlen(copy))
		i++;
	if (i == ft_strlen(copy))
		return (1);
	else
		copy[i] = '\0';
	idx = get_element_idx(arrlst, copy);
	free(copy);
	// 만약 존재하지 않는 환경변수를 입력했다면 새로 추가
	if (idx == -1)
		add_element(arrlst, arg);
	// 이미 존재하는 환경변수를 입력했을 때, 값을 수정해주는 부분
	else
	{
		free(arrlst->str_arr[idx]);
		arrlst->str_arr[idx] = ft_strdup(arg);
		if (arrlst->str_arr[idx] == NULL)
			return (1);
	}
	return (0);
}
