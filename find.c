/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 07:36:03 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 14:40:28 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 17L
int	find_max(t_stack *stk, t_id *info)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stk;
	info->size = lstsize_circle(stk);
	while (i < info->size)
	{
		if (tmp->content < stk->content)
			tmp = stk;
		stk = stk->next;
		i++;
		if (stk == tmp)
			break ;
	}
	tmp->id = info->size - 1;
	return (tmp->content);
}

// 17L
int	find_min(t_stack *stk, t_id *info)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stk;
	info->size = lstsize_circle(stk);
	while (i < info->size)
	{
		if (tmp->content > stk->content)
			tmp = stk;
		stk = stk->next;
		i++;
		if (stk == tmp)
			break ;
	}
	tmp->id = 0;
	return (tmp->content);
}

// 25L
int	find_median(t_stack *stk, t_id *info)
{
	t_stack	*tmp;
	int		larger;
	int		smaller;
	int		i;

	i = 0;
	larger = 0;
	smaller = 0;
	tmp = stk->next;
	info->boarder = info->size / 2;
	while (i < info->size)
	{
		if (tmp->content > stk->content)
			larger++;
		if (tmp->content < stk->content)
			smaller++;
		if (smaller > info->boarder || larger > info->boarder)
			return (find_median(stk->next, info));
		tmp = tmp->next;
		i++;
	}
	if (smaller == info->boarder || larger == info->boarder)
		return ((*stk).content);
	else
		return (0);
}
