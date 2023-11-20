/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 07:11:52 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 15:45:22 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 5L
static void	move_one(t_stack **dst, t_stack **src)
{
	(*src)->next = *dst;
	(*src)->prev = (*dst)->prev;
	((*dst)->prev)->next = *src;
	(*dst)->prev = *src;
	*dst = (*dst)->prev;
}

// 3L
static void	move_one_to_empty(t_stack **dst, t_stack **src)
{
	*dst = *src;
	(*dst)->next = *dst;
	(*dst)->prev = *dst;
}

//15L
void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	if (lstsize_circle(*src) == 1)
		tmp = NULL;
	else
		tmp = (*src)->next;
	((*src)->prev)->next = (*src)->next;
	((*src)->next)->prev = (*src)->prev;
	if (*dst == NULL)
		move_one_to_empty(dst, src);
	else if (*dst != NULL)
		move_one(dst, src);
	*src = tmp;
}

void	pa(t_stack **stk_a, t_stack **stk_b)
{
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	push(stk_a, stk_b);
}

void	pb(t_stack **stk_a, t_stack **stk_b)
{
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	push(stk_b, stk_a);
}

// void	pa_pb(t_stack **stk_a, t_stack **stk_b, int stk_id)
// {
// 	if (stk_id == A)
// 	{
// 		ft_putstr_fd("pa\n", STDOUT_FILENO);
// 		push(stk_a, stk_b);
// 	}
// 	if (stk_id == B)
// 	{
// 		ft_putstr_fd("pb\n", STDOUT_FILENO);
// 		push(stk_b, stk_a);
// 	}
// }
