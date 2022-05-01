/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:13 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/30 12:20:15 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
/*

<서브젝트 요구사항>
yusong
0. 새로운 커맨드 기다릴 때 프롬프트 나타나도록 할 것 
	-> history 구현
	-> ', " inhibit. 따옴표로 감싸면 String으로 받는 것 구현(단, ""안에 $는 처리 필요)
	-> 환경변수가 $뒤에 쓰이면 그 값으로 대치되는 것 구현
1. pipe |
	-> redirections <, >, <<, >> 구현
	-> executable을 search해서 launch하는 것 구현 (환경변수를 쓰던, 절대 또는 상대경로를 쓰던)
2. $? should expands to the exit status of the most recently executed foreground pipeline.


jiyoo
3. builtin 7개 구현.


4. ctrl-C ctrl-D ctrl-\ should work like in bash.


5. 기타 조건들
	-> 닫히지 않은 따옴표나 \ 또는 ;는 해석하지 말 것
	-> 전역변수는 1개를 넘게 사용하지 말 것. 그리고 그 이유에 대해서 생각해 둘 것

<구현에 요구되는 자료구조>
- 커맨드 history 저장을 위한 문자열 배열. LIFO 형태와 유사하게끔 구현되어야 함
- 환경변수의 저장을 위한 array_list


<큼직한 계획>
요구사항을 보고 큼직하게 나누고 그 뒤에 다시 세세하게 모듈로 나눈다
(모듈을 어떻게 구현할지를 알 수 있으려면 허용함수들, 미니쉘과 관련된 CS지식, bash의 작동방식에 대한 이해가 선행되어야 할 것 같다)
모듈 간 의존성을 분석하여, 추후 모듈 단위 개발을 할 때 다 짜고나서 다시 갈아엎는 일이 없도록 한다
분석을 토대로 큰 그림을 짠다 -> 로직과 거기에 요구되는 자료구조 구상
이미 구현한 libft, arraylist와 builtin 등등 모든 것들에서 에러처리 컨벤션에 맞게 추가적으로 구현해야 함.

<내가 당장 할 일>
yusong님 코드 쫙 읽어서 이해하고, 0번 어떻게 짤지 구상해서 서로 의논
내가 맡아서 구현

*/


int	main(int argc, char **argv, char **envp)
{
	t_arraylist *arrlst;

	arrlst = create_arraylist(envp);
	ft_export(arrlst, "WATER=moressang");
	ft_unset(arrlst, "USER");
	ft_export(arrlst, "NEW_USER=sexy_guy");
	ft_export(arrlst, "TERM=aaaaaaaaaaaaaaaaaaaaa");
	ft_export(arrlst, "");
	printf("\n\n%d %s\n", argc, argv[0]);
	
	return (0);
}
