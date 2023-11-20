/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:31:28 by efmacm23          #+#    #+#             */
/*   Updated: 2023/11/20 17:58:22 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 12L
void	push_swap(t_stack **stk_a, t_stack **stk_b, int num_args, t_id *info)
{
	if (num_args == 1 || check_if_in_order(*stk_a) == 0)
		return ;
	else if (num_args == 2)
		sa(stk_a);
	else if (num_args == 3)
		sort3(stk_a);
	else if (num_args == 4)
		sort4(stk_a, stk_b, info);
	else if (num_args == 5)
		sort5(stk_a, stk_b, info);
	else
		my_radix(stk_a, stk_b, num_args);
}

// 25L
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_id	info;

	if (argc < 2)
		exit (1);
	if (handle_error(&argv[1], argc - 1) != 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, &argv[1]);
	if (stack_a == NULL)
		return (1);
	info.size = lstsize_circle(stack_a);
	info.boarder = find_median(stack_a, &info);
	info.max = find_max(stack_a, &info);
	info.min = find_min(stack_a, &info);
	coord_comp(&stack_a, &info);
	push_swap(&stack_a, &stack_b, argc - 1, &info);
	free_null_list(&stack_a);
	free_null_list(&stack_b);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }
