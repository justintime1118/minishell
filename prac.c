#include "./incs/minishell.h"

// gcc -lreadline prac.c -o test

/*

<서브젝트 요구사항>

0. 새로운 커맨드 기다릴 때 프롬프트 나타나도록 할 것 V
	-> history 구현
	-> ', " inhibit. 따옴표로 감싸면 String으로 받는 것 구현(단, ""안에 $는 처리 필요)
	-> 환경변수가 $뒤에 쓰이면 그 값으로 대치되는 것 구현
1. pipe |, redirections <, >, <<, >> 
	-> 리다이렉션 기호 뒤에 아무것도 안나오거나 공백만 있는 등 에러 처리도 여기서 핸들링
	-> executable을 search해서 launch하는 것 구현 (환경변수를 쓰던, 절대 또는 상대경로를 쓰던)
2. $? should expands to the exit status of the most recently executed foreground pipeline.
3. builtin 7개 구현.
4. ctrl-C ctrl-D ctrl-\ should work like in bash.
5. 기타 사항
	-> 닫히지 않은 따옴표나 \ 또는 ;는 해석하지 말 것(해석하지 말라는 것은 그냥 그대로 literal로 넘겨주라는 뜻)
	-> 전역변수는 1개를 넘게 사용하지 말 것. 그리고 그 이유에 대해서 생각해 둘 것

<내가 할 일>
- 0번 && 5번.

*/
int main(void)
{
	char *line;

	while (1)
	{
		line = readline("jiyoo$");
		add_history(line);
		printf("%s\n", line);
		if (line[0] == 'q')
			return 0;
	}
	return 0;
}


