/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:53:09 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 16:03:01 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 13L
void	sort5(t_stack **stk_a, t_stack **stk_b, t_id *info)
{
	while (lstsize_circle(*stk_a) != 3)
	{
		if ((*stk_a)->content < info->boarder)
			pb(stk_a, stk_b);
		else
			ra(stk_a);
	}
	if (check_if_in_order(*stk_a) == NO)
		sort3(stk_a);
	if (check_order_descending(*stk_b) == NO)
		sb(stk_b);
	while (*stk_b)
		pa(stk_a, stk_b);
}

// 11L
void	sort4(t_stack **stk_a, t_stack **stk_b, t_id *info)
{
	while (lstsize_circle(*stk_a) > 3)
	{
		if ((*stk_a)->content == info->min)
			pb(stk_a, stk_b);
		else
			ra(stk_a);
	}
	if (check_if_in_order(*stk_a) == NO)
		sort3(stk_a);
	pa(stk_a, stk_b);
}

// 24L
void	sort3(t_stack **stack)
{
	int	mid;

	if (stack == NULL)
		return ;
	if (check_order_descending(*stack) == YES)
		sa(stack);
	mid = ((*stack)->next)->content;
	if (mid > (*stack)->content && mid > ((*stack)->next->next)->content)
	{
		if ((*stack)->content > ((*stack)->next->next)->content)
			rra(stack);
		else if ((*stack)->content < ((*stack)->next->next)->content)
		{
			sa(stack);
			ra(stack);
		}
	}
	else if (mid < (*stack)->content && mid < ((*stack)->next->next)->content)
	{
		if ((*stack)->content < ((*stack)->next->next)->content)
			sa(stack);
		else if ((*stack)->content > ((*stack)->next->next)->content)
			ra(stack);
	}
}
