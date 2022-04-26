/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/25 20:06:04 by jiyoo            ###   ########.fr       */
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
unset이랑 delete 구현
슬랙에서 논의한대로 add 논리 수정
환경변수 초기값은 수정 불가하게 구현. 그치만 이게 괜찮을지는 함 생각해보자
위에 다 했으면 큰 그림 나도 생각해보기

이미 구현한 arraylist와 builtin에서 에러처리 컨벤션에 맞게 추가적으로 구현.
norm 맞춰야 함
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
	char	*value;

	// name이 "환경변수명"이어야 함. 등호 이전까지만 넣어야 한다는 것
	value = getenv(name);
	// 만약 존재하지 않는 환경변수를 입력했다면 새로 추가
	if (value == NULL)
		add_element(arrlst, arg);
	// 이미 존재하는 환경변수를 입력했다면 값을 수정. 근데 얘는 조심해서 해야됨
	else
	{
		value = get_element(arrlst, name);

	}
	return (0);
}

int	unset(t_arraylist *arrlst, char *name)
{
	// 환경변수 명이 들어오면 그걸 삭제하는 것
}

int	main(int argc, char **argv, char **envp)
{
	t_arraylist *arrlst;
	
	arrlst = create_arraylist(envp);
	export(arrlst, "WATER=moressang");
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