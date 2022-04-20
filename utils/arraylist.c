#include "../incs/minishell.h"

t_arraylist* createt_arraylist(int envp_len, char **my_envp)
{
	int	i;
	t_arraylist *arrlst;
	
	arrlst = (t_arraylist *)malloc(sizeof(t_arraylist)); // 에러처리 해줄 것
	arrlst->max_len = envp_len * 2;
	arrlst->current_len = envp_len;
	arrlst->env_arr = (char **)malloc(sizeof(char *) * arrlst->max_len);
	if (arrlst->env_arr == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	for (int i = 0; i < envp_len; i++)
		arrlst->env_arr[i] = my_envp[i];
	return (arrlst);
}

void deletet_arraylist(t_arraylist** arrlst)
{
	if (*arrlst == NULL || (*arrlst)->env_arr == NULL)
	{
		printf("invalid t_arraylist\n");
		return ;
	}
	free((*arrlst)->env_arr);
	(*arrlst)->env_arr = NULL;
	free(*arrlst);
	*arrlst = NULL;
}

int ist_arraylistFull(t_arraylist* arrlst)
{
	if (arrlst == NULL || arrlst->env_arr == NULL)
	{
		printf("invalid Array List\n");
		return (ERROR);
	}
	if (arrlst->current_len == arrlst->max_len)
		return (TRUE);
	else
		return (FALSE);
}

void addALElement(t_arraylist* arrlst, char *element) 
{
	char	*value;

	value = ft_strdup(element);
	if (arrlst == NULL || arrlst->env_arr == NULL)
	{
		printf("invalid t_arraylist\n");
		return (ERROR);
	}
	if (ist_arraylistFull(arrlst) == TRUE)
	{
		printf("the t_arraylist is full\n");
		return (ERROR);
	}

	arrlst->env_arr[arrlst->current_len] = value;
	arrlst->current_len++;
}

char* getALElement(t_arraylist* arrlst, char *element)
{
	if (arrlst == NULL || arrlst->env_arr == 0)
	{
		printf("invalid t_arraylist\n");
		return (NULL);
	}
	if (position < 0 || arrlst->current_len <= position)
	{
		printf("position out of bound\n");
		return (NULL);
	}
	return (&(arrlst->env_arr[position]));
}

void displayt_arraylist(t_arraylist* arrlst)
{
	int	i;

	if (arrlst == NULL || arrlst->env_arr == 0)
	{
		printf("invalid t_arraylist\n");
		return ;
	}
	if (arrlst->current_len == 0)
	{
		printf("the t_arraylist is empty\n");
		return ;
	}
	for (i = 0; i < arrlst->current_len - 1; i++)
		printf("%d ", arrlst->env_arr[i].data);
	printf("%d\n", arrlst->env_arr[i].data);
}

void cleart_arraylist(t_arraylist* arrlst)
{
	if (arrlst == NULL || arrlst->env_arr == 0)
	{
		printf("invalid t_arraylist\n");
		return ;
	}
	for (int i = 0; i < arrlst->current_len; i++)
		arrlst->env_arr[i].data = 0;
	arrlst->current_len = 0;
}

int gett_arraylistLength(t_arraylist* arrlst)
{
	if (arrlst == NULL || arrlst->env_arr == NULL)
	{
		printf("invalid t_arraylist\n");
		return (ERROR);
	}
	return (arrlst->current_len);
}

/*
int main(void)
{
	t_arraylist *arrlst;
	t_arraylistNode node;

	node.data = 1;
	
	arrlst = createt_arraylist(10);
	
	for (int i = 0; i < 11; i++)
	{
		addALElement(arrlst, i, node);
		printf("CYCLE %d: length == %d\n", i, gett_arraylistLength(arrlst));
		node.data++;
	}
	
	if (ist_arraylistFull(arrlst) == TRUE)
		printf("TRUE: FULL\n");
	else
		printf("FALSE: NOT FULL\n");
	
	// removeALElement(arrlst, 3);
	// removeALElement(arrlst, 11);
	
	// if (ist_arraylistFull(arrlst) == TRUE)
	// 	printf("TRUE: FULL\n");
	// else
	// 	printf("FALSE: NOT FULL\n");
	
	// addALElement(arrlst, 10, node);

	// addALElement(arrlst, 3, node);
	// deletet_arraylist(arrlst);
	// cleart_arraylist(arrlst);
	// addALElement(arrlst, 0, node);
	displayt_arraylist(arrlst);
}
*/