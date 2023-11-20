/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:12:41 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 15:12:42 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **current)
{
	if (*current == NULL)
		return ;
	*current = (*current)->prev;
}
	// g_cmd_n++;

void	rra(t_stack **stk_a)
{
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	reverse_rotate(stk_a);
}

void	rrb(t_stack **stk_b)
{
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	reverse_rotate(stk_b);
}

void	rrr(t_stack **stk_a, t_stack **stk_b)
{
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
}
