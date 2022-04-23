/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/23 15:08:08 by jiyoo            ###   ########.fr       */
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
array list 만들고, api를 그에 맞게 수정하자
작은 함수들 구현

이미 구현한 arraylist와 builtin에서 에러처리 컨벤션에 맞게 추가적으로 구현.
norm 맞춰야 함
*/

void	env(t_arraylist *arrlst)
{
	display_arraylist(arrlst);
}

void	cd(char *blah)
{
	// 디렉토리를 바꿔주는 함수들 숙지하고 구현
}

void	export(char **envp)
{
	
}

int	main(int argc, char **argv, char **envp)
{
	t_arraylist *arrlst;
	arrlst = create_arraylist(envp);
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