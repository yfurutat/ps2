/**
 * @file test.h
 * @author yfurutat
 * @brief This header file is ONLY for testing the cases. 
 * 		DO NOT SUBMIT to the project repository.
 * @version 0.1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TEST_H
# define TEST_H

# include "push_swap.h"
# include <string.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_lst
{
	int				content;
	int				id;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;
	// struct s_info	*info;

typedef enum e_stack_id
{
	A,
	B,
	BOTH,
}	t_stkid;

size_t	g_cmd_n;

void	print_list(t_stack *head);
void	print_array(int arr[], int size);
int		divide_list(t_stack **stk_a, t_stack **stk_b, int pivot, int size);

#endif