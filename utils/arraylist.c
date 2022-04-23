#include "arraylist.h"

t_arraylist *create_arraylist(char **str)
{
	int	len;
	t_arraylist	*arrlst;

	arrlst = (t_arraylist *)malloc(sizeof(t_arraylist));
	if (arrlst == NULL)
		exit(1);
	len = 0;
	while(str[len] != NULL)
		len++;
	arrlst->current_len = len;
	arrlst->max_len = len * 2;
	arrlst->str_arr = (char **)malloc(sizeof(char *) * (arrlst->max_len + 1));
	arrlst->str_arr[len] = NULL;
	if (arrlst->str_arr == NULL)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	while (len-- > 0)
	{
		arrlst->str_arr[len] = ft_strdup(str[len]);
		if (arrlst->str_arr[len] == NULL)
		{
			printf("strdup failed\n");
			return (NULL);
		}
	}
	return (arrlst);
}


int is_arraylist_full(t_arraylist *arrlst)
{
	if (arrlst == NULL || arrlst->str_arr == NULL)
	{
		printf("invalid Array List\n");
		return (ERROR);
	}
	if (arrlst->current_len == arrlst->max_len)
		return (TRUE);
	else
		return (FALSE);
}

void add_element(t_arraylist *arrlst, char *element) 
{
	int		i;
	char	**new_str_arr;

	if (arrlst == NULL || arrlst->str_arr == NULL)
	{
		printf("invalid Array List\n");
		return ;
	}
	if (is_arraylist_full(arrlst) == TRUE)
	{
		i = 0;
		new_str_arr = (char **)malloc(sizeof(char *) * arrlst->max_len * 2);
		while (i < arrlst->current_len)
		{
			new_str_arr[i] = ft_strdup(arrlst->str_arr[i]);
			free(arrlst->str_arr[i++]);
		}
		free(arrlst->str_arr);
		arrlst->str_arr = new_str_arr;
	}
	arrlst->str_arr[arrlst->current_len] = ft_strdup(element);
	arrlst->current_len++;
}

// 앞부분이 element와 완전히 동일한 문자열이 있다면 그걸 반환하고 없으면 NULL을 반환
char *get_element(t_arraylist *arrlst, char *element)
{
	int		i;
	char	*ret;

	if (arrlst == NULL || arrlst->str_arr == NULL)
	{
		printf("invalid Array List\n");
		return (NULL);
	}
	i = 0;
	ret = NULL;
	while (i < arrlst->current_len)
	{
		if (ft_strncmp(element, arrlst->str_arr[i], ft_strlen(element)) == 0)
		{
			ret = arrlst->str_arr[i];
			break ;
		}
		i++;
	}
	return (ret);
}

void display_arraylist(t_arraylist *arrlst)
{
	int	i;

	if (arrlst == NULL || arrlst->str_arr == NULL)
	{
		printf("invalid Array List\n");
		return ;
	}
	i = 0;
	while (i < arrlst->current_len)
		printf("%s\n", arrlst->str_arr[i++]);
}

int	main(int argc, char **argv, char **envp)
{
	t_arraylist *arrlst;
	arrlst = create_arraylist(envp);
	add_element(arrlst, "yeah baby!");
	display_arraylist(arrlst);
	printf("%d, %s\n", argc, argv[0]);
	return (0);
}