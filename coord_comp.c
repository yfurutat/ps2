/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:46:52 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 14:47:06 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 22L
void	coord_comp(t_stack **stk, t_id *info)
{
	t_stack	*current;
	int		compressed_value;
	int		i;
	int		j;

	i = 0;
	while (i < info->size)
	{
		j = 0;
		compressed_value = 1;
		current = *stk;
		while (j < info->size)
		{
			if (current->content < (*stk)->content)
				compressed_value++;
			current = current->next;
			j++;
		}
		(*stk)->id = compressed_value;
		(*stk) = (*stk)->next;
		i++;
	}
}
