#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>

# define SUCCESS	0
# define FAIL		1

typedef struct	s_list
{
	void			*key;
	void			*content;
	struct s_list	*next;
}				t_list;


///////
typedef struct t_arraylistType
{
	int max_len;				// 최대 원소 개수
	int current_len;			// 현재 원소의 개수
	char **str_arr;				// 문자열 저장을 위한 배열
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
//////

// src
char	**parse(void);
char	convert_env(t_list **head, char **env);
char	make_el(t_list **head, char *l);

// builtin
int		ft_cd(char *path);
char	ft_echo(char **cmd);
char	ft_exit(char **cmd);
int		ft_export(t_arraylist *arrlst, char *arg);
char	ft_pwd(void);
int		ft_env(t_arraylist *arrlst);
int		ft_unset(t_arraylist *arrlst, char *name);

// engine
char	loop(t_arraylist *env);

// command
char	command_work(char **cmd, t_arraylist *env);

////////////


int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *ptr, size_t len);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *ptr, int value, size_t num);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_memcpy(void *dest, const void *src, size_t num);
void			*ft_memmove(void *dest, const void *src, size_t num);
void			*ft_memset(void *dest, int value, size_t count);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int ch);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t destsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memccpy(void *dest, const void *src, int c, size_t num);
t_list			*ft_lstnew(void *key, void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_putnbr_fd(int n, int fd);


#endif