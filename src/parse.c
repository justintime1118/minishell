/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:04:48 by yusong            #+#    #+#             */
/*   Updated: 2022/05/17 17:43:43 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unclosed_quote_checker(char *line)
{
	int	quote_flag;
	int	i;

	quote_flag = 0;
	i = 0;
	while (line[i])
	{
		if (quote_flag == 0 && (line[i] == '\'' || line[i] == '\"'))
			quote_flag = line[i];
		if (quote_flag != 0 && line[i] == quote_flag)
			quote_flag = 0;
		i++;
	}
	if (quote_flag == 0)
		return (FALSE);
	else
		return (TRUE);
}

int	nothing_after_pipe_checker(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|' && line[i + 1] != '|')
		{
			while (line[++i] == ' ')
				continue ;
			if (line[i] == '\0')
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

char	**line_process(char *line)
{
	// 무시해야 하는 경우에 에러메시지 같은 걸 출력하게 할 수도 있음
	if (unclosed_quote_checker(line) == TRUE || nothing_after_pipe_checker(line) == TRUE)
		return (NULL);
	
}

char	**parse(void)
{
	char	*line;
	char	**cmd;

	line = readline(">");
	add_history(line);
	cmd = line_process(line);
	return (cmd);
}

/*

<구현해야 하는 기능>
0. 가장 먼저 해줘야 할 것: 무시해야 하는 경우인지 확인 및 에러 체크.
	-> 무시해야 하는 경우들 (멀티라인 케이스)
		- 따옴표가 열린 뒤에 닫히지 않은 경우
		- 파이프가 나온 뒤에 명령어가 나오지 않은 경우
1. 문자열 내부 파싱
	- \랑 ;는 쌍따옴표 안에 있으면 문자로 넘겨주고 그게 아니면 그냥 삭제하고 명령어로 넘겨준다
	- 따옴표로 감싸진 것들은 한 덩어리로 취급해서 split 해준다
	- 쌍따옴표 내에 있는 $ 적절히 처리

<yusong님과 조율할 부분>
- yusong님이 구현해 둔 $환경변수 처리는 그냥 없애도 됨. 파싱 단에서 전부 처리하게끔 구현

<모듈>
- 무시 케이스 체크 모듈
	-> 안 닫힌 따옴표
	-> 파이프 뒤에 공백만 있거나 아무것도 없을 때

- 무시케이스가 아닌 문자열을 파싱해주는 모듈
	tmp에 빈 문자열을 넣어줌.
	while (readline으로 읽어들인 문자열의 끝을 만날때까지)
		if) 홑 따옴표가 나오면
			홑따옴표 끝날 때까지를 한 묶음으로 하고 맨 앞에 공백 하나 추가해서 tmp에 ft_strdup으로 임시 저장함.
		else if) 쌍 따옴표가 나오면
			if) $가 나오면
				if) 해당하는 환경변수가 존재하지 않으면
					그냥 빈 문자열로 대체
				else
					적절한 환경변수 값으로 대체
		if) 파이프나 리다이렉션(< 한개인지 << 두개 붙어있는지 나눠서 처리해주는 것 중요)이 나오면
			그 앞 뒤로 공백을 하나씩 추가해서 tmp에 ft_strjoin으로 붙여줌
				-> (공백 꼭 추가해야 하나?!?!?!?!?!?! yusong님이 짜둔 것 참고해서 결정하자)
			파이프나 리다이렉션 등 여러가지 기호들이 연속적으로 나오거나 한칸 띄우고 나오는 등의 경우들에 대해 전부 적절히 고려하여 처리해야 함
		if) $가 나오면
			if) 존재하는 환경변수이면
				적절한 환경변수 값으로 대체해 줌
			else) 
				그냥 빈문자열로 대체
		인덱스를 적절히 트랙킹하는 가운데 쭉쭉 읽어나가면 됨
	
	while문을 벗어나면 공백 기준으로 split해서 넘겨주면 끝!
	(메모리 누수 안나도록 안쓰는 문자열들은 메모리 해제 빼먹지 말고 잘 해줄 것!)
*/