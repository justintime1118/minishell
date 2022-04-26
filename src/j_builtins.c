/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/27 01:22:56 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
/*
<전체적 흐름>
미니쉘 프로그램 실행
프롬프트 나타남 <term.h> 내의 tcgetarrt, tcsetattr를 이용
명령어 입력 -> readline 이용
명령어 파싱 후 실행 -> 우리가 구현한 builtin인지, 아니면 execve로 실행시킬 것인지에 따라 다르게 돌아감. pipex에서 사용한 로직이 필요함
	우리가 구현한 builtin이라면 루틴을 호출하는 것으로 해당 기능을 구현한다.
위아래 키로 history 뜨게 하는 것 -> readline과 연관되어 있음
*/

/*
<할 일>
unset이랑 remove 구현
	-> 중간을 비우게 되면 문제가 생기고 기본 쉘의 동작과도 결과값이 다르게 나오게 됨
슬랙에서 논의한대로 add 논리 수정
	-> 얘도 마찬가지

이미 구현한 libft, arraylist와 builtin 등등 모든 것들에서 에러처리 컨벤션에 맞게 추가적으로 구현해야 함.
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