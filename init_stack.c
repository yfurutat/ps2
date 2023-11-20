/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:57:37 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 14:50:26 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 14L
void	free_null_list(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	if (*head == NULL)
		return ;
	current = *head;
	((*head)->prev)->next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
}

// 22L
static int	add_back(t_stack **head, int num)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (1);
	new->content = num;
	if (*head == NULL)
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return (0);
	}
	last = *head;
	while (last->next != *head)
		last = last->next;
	new->next = *head;
	new->prev = last;
	last->next = new;
	(*head)->prev = new;
	return (0);
}

// 9L
void	init_stack(t_stack **stack_a, char **args)
{
	while (*args != NULL)
	{
		if (add_back(stack_a, ft_atol(*args)) != 0)
		{
			free_null_list(stack_a);
			return ;
		}
		args++;
	}
}
