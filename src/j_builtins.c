/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/27 15:04:02 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
/*

<서브젝트 요구사항>
0. 새로운 커맨드 기다릴 때 프롬프트 나타나도록 할 것
	-> history 구현
	-> ', " inhibit. 따옴표로 감싸면 String으로 받는 것 구현(단, ""안에 $는 처리 필요)
	-> 환경변수가 $뒤에 쓰이면 그 값으로 대치되는 것 구현
1. pipe |
	->redirecetions <, >, <<, >> 구현
	-> executable을 search해서 launch하는 것 구현(환경변수를 쓰던, 절대 또는 상대경로를 쓰던)
2. $? should expands to the exit status of the most recently executed foreground pipeline.
3. builtin 7개 구현
4. ctrl-C ctrl-D ctrl-\ should work like in bash.

5. 기타 조건들
	-> 닫히지 않은 따옴표나 \ 또는 ;는 해석하지 말 것
	-> 전역변수는 1개를 넘게 사용하지 말 것. 그리고 그 이유에 대해서 생각해 둘 것


<구현에 요구되는 자료구조>
- 커맨드 history 저장을 위한 문자열 리스트


<할 일>
요구사항을 보고 큼직하게 나누고 그 뒤에 다시 세세하게 모듈로 나눈다
(모듈을 어떻게 구현할지를 알 수 있으려면 허용함수들, 미니쉘과 관련된 CS지식, bash의 작동방식에 대한 이해가 선행되어야 할 것 같다)
모듈 간 의존성을 분석하여, 추후 모듈 단위 개발을 할 때 다 짜고나서 다시 갈아엎는 일이 없도록 한다
분석을 토대로 큰 그림을 짠다 -> 로직과 거기에 요구되는 자료구조 구상
구현 시작!

이미 구현한 libft, arraylist와 builtin 등등 모든 것들에서 에러처리 컨벤션에 맞게 추가적으로 구현해야 함.

<전달해야 할 것들>
unset이랑 remove 구현
	-> 중간을 비우게 되면 문제가 생기고 기본 쉘의 동작과도 결과값이 다르게 나오게 됨
슬랙에서 논의한대로 add 논리 수정
	-> 얘도 마찬가지

*/

int	env(t_arraylist *arrlst)
{
	display_arraylist(arrlst);
	return (0);
}

int	cd(char *path)
{
	if (chdir(path) == -1)
	{
		printf("cd failed\n");
		return (-1);
	}
	return (0);
}


int	export(t_arraylist *arrlst, char *arg)
{
	char	*copy;
	size_t	i;
	int		idx;

	copy = ft_strdup(arg);
	// 아무 인자없이 호출하면 환경변수 목록 출력
	if (arg == NULL) // NULL로 해도 될라나??
		display_arraylist(arrlst);
	
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
	// 이미 존재하는 환경변수를 입력했을 때, 값을 수정해주는 부분. 여기에 idx 값에 제한을 걸거나 해서 실제 쉘과 최대한 맞춰야 할 듯
	else
	{
		free(arrlst->str_arr[idx]);
		arrlst->str_arr[idx] = ft_strdup(arg);
		if (arrlst->str_arr[idx] == NULL)
			return (1);
	}
	return (0);
}

// 환경변수 명이 들어오면 그걸 삭제하는 것
int	unset(t_arraylist *arrlst, char *name)
{
	remove_element(arrlst, name);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_arraylist *arrlst;
	
	arrlst = create_arraylist(envp);
	env(arrlst);
	printf("\n\n");
	export(arrlst, "WATER=moressang");
	export(arrlst, "TERM=aaaaaaaaaaaaaaaaaaaaa");
	env(arrlst);
	printf("\n\n%d %s\n", argc, argv[0]);
	return (0);
}

/*
int main(void)
{
    char *argv[] = { "/bin/zsh", "-c", "echo $USER", 0 };
    char *envp[] =
    {
        "HOME=/",
        "PATH=/bin:/usr/bin",
        "TZ=UTC0",
        "USER=beelzebub",
        "LOGNAME=tarzan",
        0
    };
    execve(argv[0], &argv[0], envp);
    fprintf(stderr, "Oops!\n");
    return -1;
}
*/