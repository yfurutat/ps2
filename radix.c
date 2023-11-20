/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:18:40 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 15:07:46 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_biggest_bit(int num)
// {
// 	int	biggest_bit;

// 	biggest_bit = 0;
// 	while ((num >> biggest_bit) != 0)
// 		biggest_bit++;
// 	return (biggest_bit);
// }
	// printf("B: %d -> %d\n", num, biggest_bit);
	// biggest_bit = find_biggest_bit(max);
	// unsigned int	biggest_bit;
	// while (bitmask && check_if_in_order(*stack_a) == NO)
	// while (bitmask)

// 19L
void	my_radix(t_stack **stack_a, t_stack **stack_b, int max)
{
	int				i;
	unsigned int	bitmask;

	bitmask = 1;
	while (check_if_in_order(*stack_a) == NO)
	{
		i = 0;
		while (i < max && *stack_a)
		{
			if (!((*stack_a)->id & bitmask))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bitmask <<= 1;
	}
}
