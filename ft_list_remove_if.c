/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/
#include "ft_list.h"
#include <stdlib.h>

/* 
*	opted against attempting to free the void *data within the node, as this could point to anything (i.e. potentially
*	something un-freeable).
*/
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;
	t_list *tmp;

	lst = *begin_list;
	/* check if first node in list needs to be removed */
	while (lst && !cmp(data_ref, lst->data))
	{
		*begin_list = (*begin_list)->next;
		free(lst);
		lst = *begin_list;	
	}
	/* then check the rest of the list, removing nodes where appropriate, reconnecting surrounding pointers */
	while (lst)
	{
		if (lst->next && !cmp(data_ref, lst->next->data))
		{
			tmp = lst->next;
			lst->next = lst->next->next;
			free(tmp);	
		}
		else
			lst = lst->next;
	}
}
