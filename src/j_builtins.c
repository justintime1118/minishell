/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/25 09:24:23 by jiyoo            ###   ########.fr       */
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
그 외에 파싱 등등 전체적인 구조 어떻게 구현할지 구상

이미 구현한 arraylist와 builtin에서 에러처리 컨벤션에 맞게 추가적으로 구현.
norm 맞춰야 함
*/

void	env(t_arraylist *arrlst)
{
	display_arraylist(arrlst);
}

void	cd(char *path)
{
	if (chdir(path) == -1)
		printf("cd failed\n");
}

void	export(t_arraylist *arrlst, char *arg)
{
	add_element(arrlst, arg);
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