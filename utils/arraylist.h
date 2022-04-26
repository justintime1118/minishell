#ifndef _ARRAYLIST_
#define _ARRAYLIST_

# include "../incs/minishell.h"

typedef struct t_arraylistType
{
	int max_len;				// 최대 원소 개수
	int current_len;			// 현재 원소의 개수
	char **str_arr;			// 문자열 저장을 위한 배열
} t_arraylist;

t_arraylist*	create_arraylist(char **str);
int				is_arraylist_full(t_arraylist* arrlst);
void			add_element(t_arraylist* arrlst, char *element);
void			remove_element(t_arraylist* arrlst, char *element);
int				get_element_idx(t_arraylist* arrlst, char *element);
void			display_arraylist(t_arraylist* arrlst);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
