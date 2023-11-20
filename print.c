#include "push_swap.h"
#include "test.h"

/**
 * 
 * DO NOT FORGET!!!!!!!!!!!!!!!DO NOT FORGET!!!!!!!!!!!!!!!
 * DO NOT FORGET!!!!!!!!!!!!!!!DO NOT FORGET!!!!!!!!!!!!!!!
 * 
 */
void	print_list(t_stack *head)
{
	t_stack	*tmp;

	if (head == NULL)
	{
		printf("EMPTY STACK\n");
		return ;
	}
	// DO NOT INCLUDE THIS FILE WHEN COMPILING
	tmp = head;
	while (tmp->next != head)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
}

void	print_array(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

// int	main(void)
// {
// 	// int		arr[] = {64, 34, 25, 12, 22, 11, 90};
// 	// int		arr[] = {64, 34, 25, 22, 11, 90};
// 	int		arr[] = {11, 22, 64, 34, 25, 90};
// 	// int		arr[] = {-6, 12, 90};
// 	// int		arr[] = {64, 34, 12, 22, 90};
// 	// int		arr[] = {64, 34, 25, 11, 90};
// 	size_t	size;

// 	size = sizeof(arr) / sizeof(arr[0]);
// 	// printf("%lu\n", sizeof(arr));
// 	// printf("%lu\n", sizeof(arr[0]));
// 	printf("%lu\n", size);
// 	printf("unsorted array: ");
// 	print_array(arr, size);
// 	quick_sort(arr, 0, size - 1);
// 	printf("Sorted array: ");
// 	print_array(arr, size);
// 	return (0);
// }


// int	divide_list(t_stack **stk_a, t_stack **stk_b, int pivot, int size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (*stk_a && i < size && j < pivot)
// 	{
// 		if ((*stk_a)->id < pivot)
// 		{
// 			pb(stk_a, stk_b);
// 			j++;
// 		}
// 		*stk_a = (*stk_a)->next;
// 		i++;
// 	}
// 	return (j);
// }

// void	main_sort(t_stack **stk_a, t_stack **stk_b, t_id *info)
// {
// 	int	pivot;
// 	int	next;
// 	int	rest;

// 	next = 0;
// 	rest = info->size;
// 	pivot = 2;
// 	while (*stk_a && rest)
// 	{
// 		next = divide_list(stk_a, stk_b, pivot, rest);
// 		rest -= next;
// 		pivot += 2;
// 	}
// }
