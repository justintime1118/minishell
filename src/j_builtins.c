/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/20 00:33:09 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
// env - no option, export - no option, cd - only relative or absolute paths

/*
<전체적 흐름>
미니쉘 프로그램 실행
프롬프트 나타남
명령어 입력 -> history 저장됨
명령어 파싱 후 실행 -> 우리가 구현한 것이냐, 아니면 execve로 실행시킬 것이냐에 따라 다르게 돌아감. pipex에서 사용한 로직이 필요함
우리가 구현한 builtin이라면 루틴을 호출하는 것으로 해당 기능을 구현한다
*/

/*
<내가 만들 builtin>
env
- envp를 가져와서 출력

export
- 환경변수를 건드리는 함수들을 공부한 뒤에 구현

cd
- working directory를 건드리는 함수들을 공부한 뒤에 구현
*/

void	env(char **envp)
{
	for (int i = 0; envp[i] != NULL; i++)
		printf("%s\n", envp[i]);
}

void	cd(char *blah)
{
	
}

void	export(char **envp)
{
	
}

int main(int argc, char **argv, char **envp)
{
	env(envp);
	return (0);
}