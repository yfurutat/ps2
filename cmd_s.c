/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:12:32 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 15:12:33 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(t_stack **current)
// {
// 	t_stack	*tmp;

// 	if (*current == NULL)
// 		return ;
// 	tmp = *current;
// 	*current = ((*current)->next);
// 	((*current)->next) = tmp;
// }

void	swap(t_stack **current)
{
	int	tmp;

	if (*current == NULL)
		return ;
	tmp = (*current)->content;
	(*current)->content = ((*current)->next)->content;
	((*current)->next)->content = tmp;
}
	// g_cmd_n++;

//1.
void	sa(t_stack **stk_a)
{
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	swap(stk_a);
}

void	sb(t_stack **stk_b)
{
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	swap(stk_b);
}

void	ss(t_stack **stk_a, t_stack **stk_b)
{
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	swap(stk_a);
	swap(stk_b);
}

// //2.
// void	cmd_swap(t_stack **stk_a, t_stack **stk_b, int stk_id)
// {
// 	if (stk_id == A)
// 	{
// 		ft_putstr_fd("sa\n", STDOUT_FILENO);
// 		swap(stk_a);
// 	}
// 	if (stk_id == B)
// 	{
// 		ft_putstr_fd("sb\n", STDOUT_FILENO);
// 		swap(stk_b);
// 	}
// 	if (stk_id == BOTH)
// 	{
// 		ft_putstr_fd("ss\n", STDOUT_FILENO);
// 		swap(stk_a);
// 		swap(stk_b);
// 	}
// }

// //3.
// void	sa_sb(t_stack **stk, int stk_id)
// {
// 	if (stk_id == A)
// 		ft_putstr_fd("sa\n", STDOUT_FILENO);
// 	if (stk_id == B)
// 		ft_putstr_fd("sb\n", STDOUT_FILENO);
// 	swap(stk);
// }

// void	ss(t_stack **stk_a, t_stack **stk_b)
// {
// 	ft_putstr_fd("ss\n", STDOUT_FILENO);
// 	swap(stk_a);
// 	swap(stk_b);
// }
