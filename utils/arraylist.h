#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct t_arraylistType
{
	int max_len;				// 최대 원소 개수
	int current_len;			// 현재 원소의 개수
	char **env_arr;			// 문자열 저장을 위한 배열
} t_arraylist;

t_arraylist*	createt_arraylist(int max_len, char **my_envp);
void 			deletet_arraylist(t_arraylist** arrlst);
int				ist_arraylistFull(t_arraylist* arrlst);
void			addALElement(t_arraylist* arrlst, char *env);
char*			getALElement(t_arraylist* arrlst, char *env);
void			displayt_arraylist(t_arraylist* arrlst);
void			cleart_arraylist(t_arraylist* arrlst);
int				gett_arraylistLength(t_arraylist* arrlst);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
