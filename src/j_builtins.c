/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/20 17:26:42 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
/*
<전체적 흐름>
미니쉘 프로그램 실행
프롬프트 나타남
명령어 입력 -> history 저장됨
명령어 파싱 후 실행 -> 우리가 구현한 것이냐, 아니면 execve로 실행시킬 것이냐에 따라 다르게 돌아감. pipex에서 사용한 로직이 필요함
우리가 구현한 builtin이라면 루틴을 호출하는 것으로 해당 기능을 구현한다
*/

/*
<할 일>
execve의 작동방식부터 공부
envp를 가져와서 복사본을 만든다고 가정
만든 복사본을 arrlst로 바꾼다고 가정

다 만들고나서 yusong님이랑 에러처리는 어떻게 할지 맞추고 에러처리 및 norm도 다 해줘야 함
*/

void	env(char **my_envp)
{
	for (int i = 0; my_envp[i] != NULL; i++)
		printf("%s\n", my_envp[i]);
}

void	cd(char *blah)
{
	// 디렉토리를 바꿔주는 함수들 숙지하고 구현
}



void	export(char **envp)
{
	// arraylist 먼저 구현하고 거기에 있는 api로 export 기능 구현
}

int main(int argc, char **argv, char **envp)
{
	env(envp);
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