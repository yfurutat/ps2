/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 07:36:16 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 14:45:55 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **current)
{
	if (*current == NULL)
		return ;
	*current = (*current)->next;
}

void	ra(t_stack **stk_a)
{
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	rotate(stk_a);
}

void	rb(t_stack **stk_b)
{
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	rotate(stk_b);
}

void	rr(t_stack **stk_a, t_stack **stk_b)
{
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	rotate(stk_a);
	rotate(stk_b);
}
